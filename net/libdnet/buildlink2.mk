# $NetBSD$
#
# This Makefile fragment is included by packages that use libdnet.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBDNET_BUILDLINK2_MK)
LIBDNET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdnet
BUILDLINK_DEPENDS.libdnet?=		libdnet>=1.7
BUILDLINK_PKGSRCDIR.libdnet?=		../../net/libdnet

EVAL_PREFIX+=	BUILDLINK_PREFIX.libdnet=libdnet
BUILDLINK_PREFIX.libdnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdnet+=	include/dnet.h
BUILDLINK_FILES.libdnet+=	include/dnet/*
BUILDLINK_FILES.libdnet+=	lib/libdnet.*

BUILDLINK_TARGETS+=	libdnet-buildlink

libdnet-buildlink: _BUILDLINK_USE

.endif	# LIBDNET_BUILDLINK2_MK
