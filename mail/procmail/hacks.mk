# $NetBSD$

### [Fri Dec 23 04:33:11 UTC 2005 : jlam]
### Inlining functions seems to cause strstr() to enter an infinite loop
### on Solaris, so disable it.  This fixes PR pkg/30999.
###
.if ${OPSYS} == "SunOS"
PKG_HACKS+=	solaris-inline
CFLAGS+=	-fno-inline-functions
.endif
