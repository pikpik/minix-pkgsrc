# $NetBSD: buildlink2.mk,v 1.8 2003/12/05 09:16:33 adam Exp $
#

.if !defined(GNUSTEP_MAKE_BUILDLINK2_MK)
GNUSTEP_MAKE_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			gnustep-make
BUILDLINK_DEPENDS.gnustep-make?=	gnustep-make>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-make?=	../../devel/gnustep-make

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnustep-make=gnustep-make
BUILDLINK_PREFIX.gnustep-make_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	gnustep-make-buildlink

gnustep-make-buildlink: _BUILDLINK_USE

.endif	# GNUSTEP_MAKE_BUILDLINK2_MK
