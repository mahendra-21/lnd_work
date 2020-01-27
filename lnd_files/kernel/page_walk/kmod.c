/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/pgtable.h>
#include <asm/highmem.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/current.h>
#include <linux/path.h>

MODULE_LICENSE("Dual BSD/GPL");

/* Constants **/
#define FIRST_MINOR     10
#define NR_DEVS 1 // Number of device numbers

// Function Declarations for syscall definitions
int myOpen (struct inode *inode, struct file *filep);
int myRelease (struct inode *in, struct file *fp);
long myIoctl (struct file *var, unsigned int uin, unsigned long ulin);

// Initialization routines
static int myInit (void);
static void myExit (void);

struct file_operations fops = {
		.owner = THIS_MODULE,
		.open = myOpen,
		.release = myRelease,
		.unlocked_ioctl = myIoctl
};

/* Global variables */
char *devname; // contains device name
int majNo;
static dev_t mydev; // encodes major number and minor number
struct cdev *my_cdev; // holds character device driver descriptor

/* To accept input from the command line */
module_param(devname, charp, 0000);

// class and device structures
static struct class *mychar_class;
static struct device *mychar_device;


/*
 * myOpen : open function of the pseudo driver
 */

int myOpen (struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "Open successful\n");
    return 0;
}

/*
 * myRelease : close function of the pseudo driver
 */

int myRelease (struct inode *in, struct file *fp)
{
    printk(KERN_INFO "File released \n");
    return 0;
}

long myIoctl(struct file *var, unsigned int uin, unsigned long ulin)
{
    struct task_struct *my_task;
    pgd_t *ptr;
    pte_t *ptr1;
    unsigned long physical;
    void *virtual;
    unsigned long *temp1;
    unsigned int offset;
    int temp = 1024;
    int loop = 0;
    
	printk(KERN_INFO "Control device %d\n", uin);
	printk(KERN_INFO "Current -> %p\n", current);
	
	my_task = current;
	ptr = my_task -> mm -> pgd;

	offset = ulin >> 22;
	physical = (ptr + offset ) -> pgd;

	printk("phys. -> 0x%.8lx\n", physical);
	while (temp >= loop)
		printk("%d	0x%.8lx\n", ((loop++) + 1), *(ptr + loop));	
	
	ptr1 = kmap(pfn_to_page(physical >> 12));
	
	printk("virt.ptr1 -> 0x%.8lx\n", ptr1);

	offset = (ulin << 10) >> 22;
	physical = (ptr1 + offset) -> pte;
	
	printk("phys. -> 0x%.8lx\n", physical);

	loop = 0;
	while (temp >= loop)
		printk("%d	0x%.8lx\n", ((loop++) + 1), (physical + loop) -> pte);
	
	virtual = (void *)(kmap(pfn_to_page(physical >> 12)));	
	
	physical = (unsigned long)virtual;

	offset = ulin & 0xfff;
        temp1 = (unsigned long *)(physical + offset);

	printk(KERN_INFO "value -> %d\n", *temp1);
	*temp1 = 5;
	printk(KERN_INFO "value -> %d\n", *temp1);
	return 0;
}
/* 
 * myInit : init function of the kernel module 
 */

static int __init myInit(void)
{
    int ret = -ENODEV;
    int status;

    printk(KERN_INFO "Initializing Character Device \n");

    // Allocating Device Numbers
    status = alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);
    if (status < 0)
    {
        printk (KERN_NOTICE "Device numbers allocation failed: %d\n", status);
        goto err;
    }

    printk (KERN_INFO "Major number allocated = %d \n", MAJOR(mydev));
    my_cdev = cdev_alloc(); // Allocate memory for my_cdev
    if (my_cdev == NULL) {
        printk (KERN_ERR "cdev_alloc failed \n");
        goto err_cdev_alloc;
    }

    cdev_init(my_cdev, &fops); // Initialize my_cdev with fops
    my_cdev -> owner = THIS_MODULE;

    status = cdev_add (my_cdev, mydev, NR_DEVS); // Add my_cdev to the list
    if (status) {
        printk (KERN_ERR "cdev_add failed \n");
        goto err_cdev_add;
    }

    // Create a class and entry in sysfs
    mychar_class = class_create(THIS_MODULE, devname);
    if (IS_ERR(mychar_class)) {
        printk (KERN_ERR "class_create() failed \n");
        goto err_class_create;
    }

    // Create mychar_device in sysfs and device 
    // entry will be made in /dev directory
    mychar_device = device_create (mychar_class, NULL, mydev, NULL, devname);
    if (IS_ERR(mychar_device)) {
        printk (KERN_ERR "device_create() failed \n");
        goto err_device_create;
    }

    return 0;

err_device_create:
    class_destroy (mychar_class);

err_class_create:
    cdev_del (my_cdev);

err_cdev_add:
    kfree (my_cdev);

err_cdev_alloc:
    unregister_chrdev_region (mydev, NR_DEVS);

err:
    return ret;
}

/*
 * myExit : cleanup function of the module
 */

static void myExit (void)
{
    printk (KERN_INFO "Exiting the Character Driver \n");

    device_destroy (mychar_class, mydev);
    class_destroy (mychar_class);
    cdev_del (my_cdev);
    unregister_chrdev_region (mydev, NR_DEVS);

    return;
}

module_init(myInit);
module_exit(myExit);
