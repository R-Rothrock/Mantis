// config.h
// Configurations for the command & control system

// Since firewalls exist, <citation needed> it's important to be
// evasive. Luckily, there are multiple ways to do this. I don't
// necessarily know which is best, but hey, that's what this file is
// here for; options. And so, here are options.

// DEFAULT SETTINGS
// IMAP tunneling
// XOR encryption (if you'd even call it that) (key is 'l')
// Controller IP is not set by default (it's commented out)

#ifndef __CNC_CONFIG_H
#define __CNC_CONFIG_H

/***************
 *** Host IP ***
 ***************/

//#define CNC_CONFIG_CONTROLLER_IP "4.20.6.9"

/****************************
 *** Protocol Obfuscation ***
 ****************************/

// DNS Tunneling
// Pretty effective, but also pretty standard. Not too creative...
//#define CNC_CONFIG_PROTOCOL_DNS

// IMAP Tunneling
// Never heard of it? Correct, you haven't.
//#define CNC_CONFIG_PROTOCOL_IMAP

/************************
 *** Data Obfuscation ***
 ************************/

// XOR encryption
// Yeah, it's kind of meh... whatever
//#define CNC_CONFIG_DATA_XOR 'l' // change key however

// AES256 with pre-defined key
// Makes an AES256 key with SHA256 on a passphrase. Gives REs a run
// for their money.
//#define CNC_CONFIG_DATA_AES256_KEY "thisIsOurKey"

// AES256 with a Diffie-Hellman implementation
// Kinda legit... very bulky. Currently just a hypothetical.
//#define CNC_CONFIG_DATA_AES256_DIFFIE_HELLMAN

/**************************************
 *** Configs End Here - Don't Touch ***
 **************************************/

#if !defined(CNC_CONFIG_PROTOCOL_DNS) && !defined(CNC_CONFIG_PROTOCOL_IMAP)
#  warning "CNC protocol not configured - see src/CNC_host/config.h"
#  define NOT_CONFIGURED
#endif

#if !defined(CNC_CONFIG_DATA_XOR) && !defined(CNC_CONFIG_DATA_AES256_KEY) && !defined(CNC_CONFIG_DATA_AES256_DIFFIE_HELLMAN)
#  warning "CNC data obfuscation not configured - see src/CNC_host/config.h"
#  define NOT_CONFIGURED
#endif

#if !defined(CNC_CONFIG_CONTROLLER_IP)
#  warning "CNC controller IP not defined - see src/CNC_host/config.h"
#  define NOT_CONFIGURED
#endif

#ifdef NOT_CONFIGURED
#  error "Did you even read the readme?"
#endif

#endif /* __CNC_CONFIG_H */

