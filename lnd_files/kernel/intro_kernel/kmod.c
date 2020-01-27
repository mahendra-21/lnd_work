/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/current.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <linux/path.h>
#include <linux/dcache.h>

MODULE_LICENSE("Dual BSD/GPL");

/* Constants **/
#define FIRST_MINOR     10
#define NR_DEVS 1 // Number of device numbers
#define LEN 128

// Function Declarations for syscall definitions
int myOpen (struct inode *inode, struct file *filep);
int myRelease (struct inode *in, struct file *fp);
long myIoctl (struct file *var, unsigned int uin, unsigned long ulin);
void my_maps(struct vm_area_struct *);

// Initialization routines
static int myInit (void);
static void myExit (void);

struct file_operations fops = {
		.owner = THIS_MODULE,
		.open = myOpen,
		.release = myRelease,
//		.unlocked_ioctl = myIoctl
};

/* Global variables */
char *devname; // contains device name
int majNo;
static dev_t mydev; // encodes major number and minor number
struct cdev *my_cdev; // holds character device driver descriptor

#if 0
struct task_struct *my_var; // creating instance to tast_struct structure
struct vm_area_struct *help;
unsigned long flag;
char ch1;
char ch2;
char ch3;
char ch4;
struct path name;
int i;
int count;
char ptr[LEN][LEN];
#endif 

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

#if 0
long myIoctl(struct file *var, unsigned int uin, unsigned long ulin)
{
    printk(KERN_INFO "Control device %d\n", uin);
    printk(KERN_INFO "Current -> %p\n", current);
    my_var = current;
    
    my_maps(my_var -> mm -> mmap);
//	printk(KERN_INFO "%p-%p\n", (void *)my_var -> mm -> mmap -> vm_start, (void *)my_var -> mm -> mmap -> vm_end);
	help = my_var -> mm -> mmap;


	do {
		flag = help -> vm_flags;

		ch1 = (VM_READ & flag)? 'r': '-';
		ch2 = (VM_WRITE & flag)? 'w': '-';
		ch3 = (VM_EXEC & flag)? 'x': '-';
		ch4 = 'p';
		
		printk(KERN_INFO "%.8lx - %.8lx %c%c%c%c ", help -> vm_start, 
					help -> vm_end, ch1, ch2, ch3, ch4);

		if (help -> vm_file) {
			name = help -> vm_file -> f_path;
			struct dentry *dnt = name.dentry;
			count = 0;
			while (1) {
				ptr[count] = dnt -> d_name.name;
				dnt = dnt -> d_parent;

				if (ptr[count][0] == '/') break;

				count ++;
			}
			for (i = count - 1; i >= 0; i--)
				printk("/%s", ptr[i]);
		}
		printk("\n");

		help = help -> vm_next;
	} while (NULL != help ); 

    return 0;
}

void my_maps(struct vm_area_struct *help) {

	if (NULL == help)
		return;
	else 
		printk(KERN_INFO "%lx - %lx\n", help -> vm_start, help -> vm_end);

	my_maps(help -> vm_next);
} 
#endif 

/* 
 * myInit : init function of the kernel module 
 */

static int __init myInit (void)
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
