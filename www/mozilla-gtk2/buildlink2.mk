# $NetBSD$
#

.if !defined(MOZILLA_GTK2_BUILDLINK2_MK)
MOZILLA_GTK2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mozilla-gtk2
BUILDLINK_DEPENDS.mozilla-gtk2?=	mozilla-gtk2>=1.6nb1
BUILDLINK_PKGSRCDIR.mozilla-gtk2?=	../../www/mozilla-gtk2

EVAL_PREFIX+=	BUILDLINK_PREFIX.mozilla-gtk2=mozilla-gtk2
BUILDLINK_PREFIX.mozilla-gtk2=	${LOCALBASE}

BUILDLINK_FILES.mozilla-gtk2+=	include/mozilla-gtk2/*.h
BUILDLINK_FILES.mozilla-gtk2+=	include/mozilla-gtk2/*/*.h
BUILDLINK_FILES.mozilla-gtk2+=	include/mozilla-gtk2/*/*/*.h

BUILDLINK_FILES.mozilla-gtk2+=	lib/mozilla-gtk2/lib*.*

.include	"../../graphics/freetype2/buildlink2.mk"
.include	"../../graphics/jpeg/buildlink2.mk"
.include	"../../graphics/png/buildlink2.mk"
.include	"../../net/libIDL/buildlink2.mk"
.include	"../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	mozilla-gtk2-buildlink

mozilla-gtk2-buildlink: _BUILDLINK_USE

.endif	# MOZILLA_GTK2_BUILDLINK2_MK
