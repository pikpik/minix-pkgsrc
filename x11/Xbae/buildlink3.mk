# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:13 jlam Exp $

BUILDLINK_TREE+=	Xbae

.if !defined(XBAE_BUILDLINK3_MK)
XBAE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xbae+=	Xbae>=4.8.4
BUILDLINK_ABI_DEPENDS.Xbae+=	Xbae>=4.51.01nb2
BUILDLINK_PKGSRCDIR.Xbae?=	../../x11/Xbae

.include "../../mk/motif.buildlink3.mk"
.endif # XBAE_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xbae
