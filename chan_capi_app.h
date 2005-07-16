/*
 * (CAPI*)
 *
 * An implementation of Common ISDN API 2.0 for Asterisk
 *
 * include file for helper applications
 *
 * Copyright (C) 2005 Cytronics & Melware
 *
 * Armin Schindler <armin@melware.de>
 * 
 * Reworked, but based on the work of
 * Copyright (C) 2002-2005 Junghanns.NET GmbH
 *
 * Klaus-Peter Junghanns <kapejod@ns1.jnetdns.de>
 *
 * This program is free software and may be modified and 
 * distributed under the terms of the GNU Public License.
 */

#ifndef _ASTERISK_CAPI_IF_H
#define _ASTERISK_CAPI_IF_H

/* exported symbols from chan_capi */

/* important things we need */
extern unsigned ast_capi_ApplID;
extern _cword get_ast_capi_MessageNumber(void);
extern int capidebug;
extern ast_mutex_t verbose_lock;

extern int capi_call(struct ast_channel *c, char *idest, int timeout);
extern int capi_detect_dtmf(struct ast_channel *c, int flag);
extern MESSAGE_EXCHANGE_ERROR _capi_put_cmsg(_cmsg *CMSG);

/*
 * helper for ast_verbose with different verbose settings
 */
#define cc_ast_verbose(o_v, c_d, text...)				\
	do { 								\
		if ((o_v == 0) || (option_verbose > o_v)) {		\
			if ((!c_d) || ((c_d) && (capidebug))) {		\
				ast_mutex_lock(&verbose_lock);		\
				ast_verbose(text);			\
				ast_mutex_unlock(&verbose_lock);	\
			}						\
		}							\
	} while(0)


#endif
