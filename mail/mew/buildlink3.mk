# $NetBSD: buildlink3.mk,v 1.1 2007/10/29 12:41:18 uebayasi Exp $
#

BUILDLINK_TREE+=	mew

.if !defined(MEW_BUILDLINK3_MK)
MEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mew+=	${EMACS_PKGNAME_PREFIX}mew>=5
BUILDLINK_PKGSRCDIR.mew?=	../../mail/mew

BUILDLINK_CONTENTS_FILTER.mew=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # MEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-mew
