# $NetBSD: arch.mk,v 1.1 2002/11/25 11:01:16 schmonz Exp $

.if !defined(SUSE_ARCH_MK)
SUSE_ARCH_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "powerpc"
SUSE_ARCH?=	ppc
.else
SUSE_ARCH?=	${MACHINE_ARCH}
.endif

.endif # SUSE_ARCH_MK
