# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:18:23 joerg Exp $

BUILDLINK_DEPMETHOD.videoproto?=	build

BUILDLINK_TREE+=	videoproto

.if !defined(VIDEOPROTO_BUILDLINK3_MK)
VIDEOPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.videoproto+=	videoproto>=2.2.1
BUILDLINK_PKGSRCDIR.videoproto?=	../../x11/videoproto
.endif # VIDEOPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-videoproto
