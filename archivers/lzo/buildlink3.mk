# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_TREE+=	lzo

.if !defined(LZO_BUILDLINK3_MK)
LZO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lzo+=		lzo>=2.01
BUILDLINK_PKGSRCDIR.lzo?=	../../archivers/lzo
.endif # LZO_BUILDLINK3_MK

BUILDLINK_TREE+=	-lzo
