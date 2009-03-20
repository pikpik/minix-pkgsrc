# $NetBSD: buildlink3.mk,v 1.1 2008/10/06 07:24:31 uebayasi Exp $
#

BUILDLINK_TREE+=	riece

.if !defined(RIECE_BUILDLINK3_MK)
RIECE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.riece+=	${EMACS_PKGNAME_PREFIX}riece>=4
BUILDLINK_PKGSRCDIR.riece?=	../../chat/riece

BUILDLINK_CONTENTS_FILTER.riece=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # RIECE_BUILDLINK3_MK

BUILDLINK_TREE+=	-riece
