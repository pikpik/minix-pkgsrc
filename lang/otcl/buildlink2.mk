# $NetBSD$

.if !defined(OTCL_BUILDLINK2_MK)
OTCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		otcl
BUILDLINK_DEPENDS.otcl?=		otcl>=1.0rc8
BUILDLINK_PKGSRCDIR.otcl?=	../../lang/otcl

EVAL_PREFIX+=		BUILDLINK_PREFIX.otcl=otcl
BUILDLINK_PREFIX.otcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.otcl+=	include/otcl.h
BUILDLINK_FILES.otcl+=	lib/libotcl.*

.include "../../x11/tk/buildlink2.mk"

BUILDLINK_TARGETS+=	otcl-buildlink

otcl-buildlink: _BUILDLINK_USE

.endif	# OTCL_BUILDLINK2_MK
