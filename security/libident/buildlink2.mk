# $NetBSD$
#

.if !defined(LIBIDENT_BUILDLINK2_MK)
LIBIDENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libident
BUILDLINK_DEPENDS.libident?=		libident>=0.22
BUILDLINK_PKGSRCDIR.libident?=		../../security/libident

EVAL_PREFIX+=	BUILDLINK_PREFIX.libident=libident
BUILDLINK_PREFIX.libident_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libident+=	include/ident.h
BUILDLINK_FILES.libident+=	lib/libident.*

BUILDLINK_TARGETS+=	libident-buildlink

libident-buildlink: _BUILDLINK_USE

.endif	# LIBIDENT_BUILDLINK2_MK
