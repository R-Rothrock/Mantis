// techniques.h
// The fun stuff

#ifndef __TECHNIQUES_H
#define __TECHNIQUES_H

// We'll call the first priviledge escalation technique
// "Sudo spoofing." In this technique, we will kill a process imbued
// with "Sudo Grace" (namely, a process that has used Sudo in the last
// ~15 minutes and can use Sudo again to run an admin command but
// doesn't need a password) and replace it with our own process (a
// process with the same PID), giving our new process the "Sudo
// Grace." Once this process exists, we can simply spawn a daemon
// version of itself as root and exit. Once this happens, we can exit,
// too, as our spawn has lived on.
// Additional details:
// When we kill the "graced process," we should send it SIGSEGV
// because this points to the process itself, as opposed to another
// process, which would be the case if we send something like SIGKILL.
// As for the function itself, it won't return on success; it'll kill
// itself instead. Therefore, this function will always return 0.
int sudo_spoof(void);


// As for the second techinque...
// I'm not writing this down right now
// TODO
int stack_logger_ptrace(void);
int stack_logger_wo_ptrace(void);

// Still considering whether I want to try a zero day... Probably not,
// but hey, maybe.

#endif /* __TECHNIQUES_H */

