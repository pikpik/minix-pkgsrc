# $NetBSD: buildlink2.mk,v 1.4 2002/09/05 20:43:19 jlam Exp $

.if !defined(BISON_BUILDLINK2_MK)
BISON_BUILDLINK2_MK=  # defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		bison
BUILDLINK_PKGBASE.bison=	bison
BUILDLINK_DEPENDS.bison?=	bison>=1.8
BUILDLINK_PKGSRCDIR.bison?=	../../devel/bison
BUILDLINK_DEPMETHOD.bison=	build

EVAL_PREFIX+=		BUILDLINK_PREFIX.bison=bison
BUILDLINK_PREFIX.bison_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.bison=	bin/bison

BUILDLINK_TARGETS+=	bison-buildlink

bison-buildlink: _BUILDLINK_USE

.endif  # BISON_BUILDLINK2_MK
