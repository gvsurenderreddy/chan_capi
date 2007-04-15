/*
 * (CAPI*)
 *
 * An implementation of Common ISDN API 2.0 for Asterisk
 *
 * Copyright (C) 2006-2007 Cytronics & Melware
 *
 * Armin Schindler <armin@melware.de>
 * 
 * This program is free software and may be modified and 
 * distributed under the terms of the GNU Public License.
 */
 
#ifndef _PBX_CAPI_UTILS_H
#define _PBX_CAPI_UTILS_H

/*
 * prototypes
 */
extern int capidebug;
extern char *emptyid;

extern void cc_verbose(int o_v, int c_d, char *text, ...);
extern _cword get_capi_MessageNumber(void);
extern MESSAGE_EXCHANGE_ERROR _capi_put_cmsg(_cmsg *CMSG);
extern MESSAGE_EXCHANGE_ERROR capidev_check_wait_get_cmsg(_cmsg *CMSG);
extern char *capi_info_string(unsigned int info);
extern void show_capi_info(struct capi_pvt *i, _cword info);
extern unsigned ListenOnController(unsigned long CIPmask, unsigned controller);
extern void parse_dialstring(char *buffer, char **interface, char **dest, char **param, char **ocid);
extern char *capi_number_func(unsigned char *data, unsigned int strip, char *buf);

#define capi_number(data, strip) \
  capi_number_func(data, strip, alloca(AST_MAX_EXTENSION))

#endif