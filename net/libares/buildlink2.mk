# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:32 jlam Exp $

.if !defined(LIBARES_BUILDLINK2_MK)
LIBARES_BUILDLINK2_MK=	# defined

BUILDLINK_DEPENDS.libares?=	libares>=1.1.1
BUILDLINK_PKGSRCDIR.libares?=	../../net/libares

BUILDLINK_PACKAGES+=	libares
EVAL_PREFIX+=		BUILDLINK_PREFIX.libares=libares
BUILDLINK_PREFIX.libares_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libares=		include/ares.h
BUILDLINK_FILES.libares+=	lib/libares.*

BUILDLINK_TARGETS+=	libares-buildlink

libares-buildlink: _BUILDLINK_USE

.endif	# LIBARES_BUILDLINK2_MK
