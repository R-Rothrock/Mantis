// signature.h
// what it's all about

#ifndef __SIGNATURE_H
#define __SIGNATURE_H

#define SIGNATURE_NAME "[SIGNATURE]"

static char note[] = "Made with :heart:";
static char signature = SIGNATURE_NAME;

#ifdef IS_KERNEL_MOD
MODULE_LICENSE("Unlicense, I suppose...");
MODULE_AUTHOR(SIGNATURE_NAME);
MODULE_DESCRIPTION("[DESCRIPTION]");
#endif /* IS_KERNEL_MOD */
#endif /* __SIGNATURE_H */

