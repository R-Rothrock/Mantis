// auxiliary.h
// learning about the environment around us.

#ifndef __AUXILIARY_H
#define __AUXILIARY_H

#include<fcntl.h>
#include<unistd.h>

// Checks foran  antivirus on system by looking through process names.
// 1 if antivirus is found, 0 if antivirus is not found.
int check_antivirus(void);

// Checks to see if maybe it's running as root.
int check_root(void);

// Checks the Ptrace scope permissions.
int check_ptrace_scope(void);

// Checks for internet access.
int check_internet(void);

// Checks for desktop environment.
int check_desktop(void);

// Checks for running desktop environment.
int check_live_desktop(void);

// Checks for signs of current human interaction.
int check_human(void);

// Checks whether Mantis has already infected this device.
int check_mantis(void);

// Checks the kernel module signature rules.
int check_kmod_rules(void);

#endif /* __AUXILIARY_H */

