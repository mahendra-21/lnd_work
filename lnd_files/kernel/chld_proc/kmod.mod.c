#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9555474b, "module_layout" },
	{ 0xdd52b09b, "param_ops_charp" },
	{ 0x782948, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x37a0cba, "kfree" },
	{ 0xdda0471e, "cdev_del" },
	{ 0x55f69e58, "class_destroy" },
	{ 0xd28eba3, "device_create" },
	{ 0x3294244b, "__class_create" },
	{ 0xaa453db7, "cdev_add" },
	{ 0xc0280c24, "cdev_init" },
	{ 0xe2367684, "cdev_alloc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x484e76cf, "kmap" },
	{ 0xa5c035fa, "mem_map" },
	{ 0xefe1bb7f, "current_task" },
	{ 0xecc9cdd8, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "57691FA304CDDE8AF77638A");
