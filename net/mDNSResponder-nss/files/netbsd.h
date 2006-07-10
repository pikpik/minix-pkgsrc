/* $NetBSD$ */

#include <nsswitch.h>

enum nss_status {
        NSS_STATUS_SUCCESS,
	NSS_STATUS_NOTFOUND,
	NSS_STATUS_UNAVAIL,
	NSS_STATUS_TRYAGAIN,
	NSS_STATUS_RETURN
};
