# $NetBSD: buildlink3.mk,v 1.1 2007/10/29 12:41:17 uebayasi Exp $
#

BUILDLINK_TREE+=	elib

.if !defined(ELIB_BUILDLINK3_MK)
ELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elib+=	${EMACS_PKGNAME_PREFIX}elib>=1
BUILDLINK_PKGSRCDIR.elib?=	../../devel/elib

BUILDLINK_CONTENTS_FILTER.elib=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # ELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-elib
