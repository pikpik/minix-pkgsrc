// $NetBSD$

// add necessary functions that is not provided by NetBSD's NSS

#ifndef _NSS_PGSQL_NETBSD_H
#define _NSS_PGSQL_NETBSD_H
enum nss_status {
	NSS_STATUS_SUCCESS,
	NSS_STATUS_NOTFOUND,
	NSS_STATUS_UNAVAIL,
	NSS_STATUS_TRYAGAIN,
	NSS_STATUS_RETURN
};
#endif /* _NSS_PGSQL_NETBSD_H */
