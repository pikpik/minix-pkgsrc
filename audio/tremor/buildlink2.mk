# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:17 jlam Exp $

.if !defined(TREMOR_BUILDLINK2_MK)
TREMOR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tremor
BUILDLINK_DEPENDS.tremor?=	tremor>=1.2.0
BUILDLINK_PKGSRCDIR.tremor?=	../../audio/tremor

EVAL_PREFIX+=	BUILDLINK_PREFIX.tremor=tremor
BUILDLINK_PREFIX.tremor_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tremor=	include/tremor/*
BUILDLINK_FILES.tremor+=	lib/libvorbisidec.*

BUILDLINK_TARGETS+=	tremor-buildlink

tremor-buildlink: _BUILDLINK_USE

.endif	# TREMOR_BUILDLINK2_MK
