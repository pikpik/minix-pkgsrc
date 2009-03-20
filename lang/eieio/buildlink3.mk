# $NetBSD: buildlink3.mk,v 1.1 2007/10/29 12:41:18 uebayasi Exp $
#

BUILDLINK_TREE+=	eieio

.if !defined(EIEIO_BUILDLINK3_MK)
EIEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eieio+=	${EMACS_PKGNAME_PREFIX}eieio>=0.17
BUILDLINK_PKGSRCDIR.eieio?=	../../lang/eieio

BUILDLINK_CONTENTS_FILTER.eieio=	${EGREP} '.*\.el$$|.*\.elc$$'
.endif # EIEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-eieio
