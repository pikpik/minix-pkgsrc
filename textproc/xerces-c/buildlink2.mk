# $NetBSD: buildlink2.mk,v 1.2 2003/03/22 00:40:50 salo Exp $
#
# This Makefile fragment is included by packages that use xerces-c.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(XERCES_C_BUILDLINK2_MK)
XERCES_C_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xerces-c
BUILDLINK_DEPENDS.xerces-c?=	xerces-c>=1.7.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

EVAL_PREFIX+=	BUILDLINK_PREFIX.xerces-c=xerces-c
BUILDLINK_PREFIX.xerces-c_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xerces-c=	include/xercesc/*/*/*/*
BUILDLINK_FILES.xerces-c+=	include/xercesc/*/*/*
BUILDLINK_FILES.xerces-c+=	include/xercesc/*/*
BUILDLINK_FILES.xerces-c+=	lib/libxerces-c*.*

.include "../../textproc/icu/buildlink2.mk"

BUILDLINK_TARGETS+=	xerces-c-buildlink

xerces-c-buildlink: _BUILDLINK_USE

.endif	# XERCES_C_BUILDLINK2_MK
