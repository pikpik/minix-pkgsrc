# $NetBSD$

.if !defined(BUDDY_BUILDLINK2_MK)
BUDDY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		buddy
BUILDLINK_DEPENDS.buddy?=	buddy>=2.2
BUILDLINK_PKGSRCDIR.buddy?=	../../devel/buddy

EVAL_PREFIX+=			BUILDLINK_PREFIX.buddy=buddy
BUILDLINK_PREFIX.buddy_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.buddy=		include/bdd.h
BUILDLINK_FILES.buddy+=		include/bvec.h
BUILDLINK_FILES.buddy+=		include/fdd.h
BUILDLINK_FILES.buddy+=		lib/libbdd.*

BUILDLINK_TARGETS+=	buddy-buildlink

buddy-buildlink: _BUILDLINK_USE

.endif	# BUDDY_BUILDLINK2_MK
