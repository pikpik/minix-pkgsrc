#	$NetBSD$

MKMAN=	no

.include <bsd.own.mk>

.PATH: ${BSDSRCDIR}/sbin/sysctl

BINDIR=		/sbin

.include "${BSDSRCDIR}/sbin/sysctl/Makefile"

LDADD+=	${.CURDIR}/../lib/libkver.a
CPPFLAGS+=	-I${BSDSRCDIR}/sys
LDSTATIC?=	-static
