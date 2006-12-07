#	$NetBSD: Makefile,v 1.4 2005/05/25 02:23:15 reed Exp $

PROG=   shlock

.if (${OPSYS} == SunOS || ${OPSYS} == Darwin || ${OPSYS} == DragonFly || \
    ${OPSYS} == Linux)
NOMAN=          YES
.endif

.include <bsd.prog.mk>
