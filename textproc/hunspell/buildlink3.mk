# $NetBSD: buildlink3.mk,v 1.2 2008/04/14 09:39:00 wiz Exp $

BUILDLINK_TREE+=	hunspell

.if !defined(HUNSPELL_BUILDLINK3_MK)
HUNSPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hunspell+=	hunspell>=1.2.2
BUILDLINK_PKGSRCDIR.hunspell?=		../../textproc/hunspell
.endif # HUNSPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hunspell
