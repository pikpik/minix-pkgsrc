# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:21:54 jlam Exp $

.if !defined(LIBMAD_BUILDLINK2_MK)
LIBMAD_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libmad
BUILDLINK_DEPENDS.libmad?=	libmad>=0.15.0b
BUILDLINK_PKGSRCDIR.libmad?=	../../audio/libmad

EVAL_PREFIX+=			BUILDLINK_PREFIX.libmad=libmad
BUILDLINK_PREFIX.libmad_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.libmad+=	include/mad.h
BUILDLINK_FILES.libmad+=	lib/libmad.*

BUILDLINK_TARGETS+=		libmad-buildlink

libmad-buildlink: _BUILDLINK_USE

.endif	# LIBMAD_BUILDLINK2_MK
