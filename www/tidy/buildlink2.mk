# $NetBSD$
#
# This Makefile fragment is included by packages that use tidy.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(TIDY_BUILDLINK2_MK)
TIDY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tidy
BUILDLINK_DEPENDS.tidy?=		tidy>=20031002
BUILDLINK_PKGSRCDIR.tidy?=		../../www/tidy

EVAL_PREFIX+=	BUILDLINK_PREFIX.tidy=tidy
BUILDLINK_PREFIX.tidy_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tidy+=	include/tidy/buffio.h
BUILDLINK_FILES.tidy+=	include/tidy/fileio.h
BUILDLINK_FILES.tidy+=	include/tidy/platform.h
BUILDLINK_FILES.tidy+=	include/tidy/tidy.h
BUILDLINK_FILES.tidy+=	include/tidy/tidyenum.h
BUILDLINK_FILES.tidy+=	lib/libtidy.*

BUILDLINK_TARGETS+=	tidy-buildlink

tidy-buildlink: _BUILDLINK_USE

.endif	# TIDY_BUILDLINK2_MK
