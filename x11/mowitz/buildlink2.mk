# $NetBSD$
#
# This Makefile fragment is included by packages that use Mowitz.
#

.if !defined(MOWITZ_BUILDLINK2_MK)
MOWITZ_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Mowitz
BUILDLINK_DEPENDS.Mowitz?=		Mowitz>=0.2.1
BUILDLINK_PKGSRCDIR.Mowitz?=		../../x11/mowitz

EVAL_PREFIX+=	BUILDLINK_PREFIX.Mowitz=Mowitz
BUILDLINK_PREFIX.Mowitz_DEFAULT=${X11PREFIX}
BUILDLINK_FILES.Mowitz+=	include/Mowitz/*
BUILDLINK_FILES.Mowitz+=	lib/libMowitz.*

.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	Mowitz-buildlink

Mowitz-buildlink: _BUILDLINK_USE

.endif	# MOWITZ_BUILDLINK2_MK
