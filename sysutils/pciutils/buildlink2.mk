# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:32 jlam Exp $

.if !defined(PCIUTILS_BUILDLINK2_MK)
PCIUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pciutils
BUILDLINK_DEPENDS.pciutils?=	pciutils>=2.1.11
BUILDLINK_PKGSRCDIR.pciutils?=	../../local/pciutils

EVAL_PREFIX+=			BUILDLINK_PREFIX.pciutils=pciutils
BUILDLINK_PREFIX.pciutils_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pciutils=	include/pciutils/*
BUILDLINK_FILES.pciutils+=	lib/libpciutils.a

BUILDLINK_TARGETS+=	pciutils-buildlink

pciutils-buildlink: _BUILDLINK_USE

.endif	# PCIUTILS_BUILDLINK2_MK
