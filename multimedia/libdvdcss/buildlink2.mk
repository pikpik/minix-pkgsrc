# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/28 14:25:37 recht Exp $
#

.if !defined(LIBDVDCSS_BUILDLINK2_MK)
LIBDVDCSS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvdcss
BUILDLINK_DEPENDS.libdvdcss?=		libdvdcss>=1.2.4
BUILDLINK_PKGSRCDIR.libdvdcss?=		../../multimedia/libdvdcss

EVAL_PREFIX+=	BUILDLINK_PREFIX.libdvdcss=libdvdcss
BUILDLINK_PREFIX.libdvdcss_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdvdcss+=	include/dvdcss/dvdcss.h
BUILDLINK_FILES.libdvdcss+=	lib/libdvdcss.*

BUILDLINK_TARGETS+=	libdvdcss-buildlink

libdvdcss-buildlink: _BUILDLINK_USE

.endif	# LIBDVDCSS_BUILDLINK2_MK
