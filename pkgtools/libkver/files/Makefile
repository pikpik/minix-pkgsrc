#	$NetBSD$

.include "${.CURDIR}/Makefile.inc"

SUBDIR=		lib

LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1
.if empty(LDD_SYSCTL:M*libc*)
SUBDIR+=	sysctl
.endif

.include <bsd.subdir.mk>
