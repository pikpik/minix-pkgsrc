# $NetBSD$

.if !defined(LIBTECLA_BUILDLINK2_MK)
LIBTECLA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libtecla
BUILDLINK_DEPENDS.libtecla?=	libtecla>=1.5.0
BUILDLINK_PKGSRCDIR.libtecla?=	../../devel/libtecla

EVAL_PREFIX+=			BUILDLINK_PREFIX.libtecla=libtecla
BUILDLINK_PREFIX.libtecla_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libtecla+=	include/libtecla.h
BUILDLINK_FILES.libtecla+=	lib/libtecla.*

BUILDLINK_TARGETS+=	libtecla-buildlink

libtecla-buildlink: _BUILDLINK_USE

.endif	# LIBTECLA_BUILDLINK2_MK
