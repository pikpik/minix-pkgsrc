# $NetBSD: buildlink2.mk,v 1.1 2002/08/28 16:35:37 jlam Exp $

.if !defined(SCROLLKEEPER_BUILDLINK2_MK)
SCROLLKEEPER_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=			scrollkeeper
BUILDLINK_DEPENDS.scrollkeeper?=	scrollkeeper>=0.2
BUILDLINK_PKGSRCDIR.scrollkeeper?=	../../textproc/scrollkeeper

EVAL_PREFIX+=	BUILDLINK_PREFIX.scrollkeeper=scrollkeeper
BUILDLINK_PREFIX.scrollkeeper_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.scrollkeeper+=		lib/libscrollkeeper.*

BUILDLINK_TARGETS+=			scrollkeeper-buildlink

.if exists(${LOCALBASE}/libdata/scrollkeeper)
SCROLLKEEPER_DATADIR=			${LOCALBASE}/libdata
.else
SCROLLKEEPER_DATADIR=			${BUILDLINK_PREFIX.scrollkeeper}/var/lib
.endif

scrollkeeper-buildlink: _BUILDLINK_USE

.endif	# SCROLLKEEPER_BUILDLINK2_MK
