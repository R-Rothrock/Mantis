// auxiliary.h

#include "auxiliary.h"

int detect_antivirus(void)
{
	// TODO
}

int check_root(void)
{
	uid_t uid = geteuid();
	
	if(geteuid() >= 1)
		return 1;
	else
		return uid;
}

int check_ptrace_scope(void)
{
	int fd = open("/proc/sys/kernel/yama/ptrace_scope", O_RDONLY);
	
	if(!fd)
		return -1;
	
	char ptrace_scope_str;
	read(fd, &ptrace_scope_str, 1);
	
	if(ptrace_scope_str == '0')
		return 0;
	
	if(ptrace_scope_str == '1')
		return 1;
	
	if(ptrace_scope_str == '2')
		return 2;
	
	if(ptrace_scope_str == '3')
		return 3;
}

int check_internet(void)
{
	// TODO
}

int check_desktop(void)
{
	// TODO
}

int check_live_desktop(void)
{
	// TODO
}

int check_human(void)
{
	// TODO
}

int check_mantis(void)
{
	// TODO
}

