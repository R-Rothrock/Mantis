															Mantis

Mantis is malware designed for Linux systems. It is designed to be
fully self-sufficent in all its actions, but nevertheless it has a CNC
(command 'n control) system for remote access and botnet utilization.

Mantis can do the following things on its own:
 - evaluate local attack defense systems (and hide from them)
 - be persistent on a system
 - escalate priviledges and root the kernel
 - propogate to other Linux devices
 - communicate with the control server

I will mention these in order.

                    Evaluating Defense Systems
Mantis is capable of finding the precenses of antiviruses, both
installed and running, on the system it has infected. Additionally, it
knows if/when to take measures to hide from them and to disable them
down the line. This doesn't just apply to antiviruses, though; Mantis
will detect desktop environments, signs of human activity, etc.

                            Persistence
Mantis utilizes simple systemd to gain persistence on a system. It's
not overly creative, but it's standard enough that it won't raise any
red flags.

                        Rooting a System
Man has the tools required to attempt to root a system. It does this
by utilizing processes utilizing Sudo run under the same user. For
specifics on the technique used, refer to `src/techniques.h`. Once
Mantis manages to escalate priviledges, it loads itself into the
kernel, and does, ya know, rootkit things.

                            Propogation
Mantis has the ability to attempt to propogate via removable media.
It places itself in files and highjacks autorun software.

              Communication With The Control Server
Mantis can communicate with the control server via two methods, one of
which has to be chosen before compile time (look below). The first of
these two methods is using DNS tunneling to exfiltrate data back and
forth from a controlled server. The second method is a similar
concept, except Mantis utilizes IMAP to exfiltrate data instead of
DNS.

                              Building
Hey, real quick, before you build:
This project is under the `unlicense`, meaning I'm not liable for
any/all immature stupidity you try (or, more correctly, try to do and
fail) with my software. This isn't Hollywood; go read a book.

With that out of the way...

First, for 'production' compilation, you'll need to uncomment lines 9
and 10 of `makefile`. Now you'll have to configure options in
`src/cnc/config.h` to setup the CNC system. Now you can run
`make` and it will build both Mantis and the control server program.

																Why?
Instead of making a simple PoC, I wanted to attempt to implement all
the things specified here. It's more fun that way.

Dixi.

