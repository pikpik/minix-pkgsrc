# $NetBSD$

.ifndef SUSE_ARCH_MK
SUSE_ARCH_MK=1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "powerpc"
SUSE_ARCH?=	ppc
.else
SUSE_ARCH?=	${MACHINE_ARCH}
.endif

.endif # SUSE_ARCH_MK
