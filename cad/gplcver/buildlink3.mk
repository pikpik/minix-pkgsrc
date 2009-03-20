# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_TREE+=	gplcver

.if !defined(GPLCVER_BUILDLINK3_MK)
GPLCVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gplcver+=	gplcver>=2.11a
BUILDLINK_PKGSRCDIR.gplcver?=	../../cad/gplcver
.endif # GPLCVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gplcver
