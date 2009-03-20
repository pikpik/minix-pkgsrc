# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:47:55 joerg Exp $

BUILDLINK_DEPMETHOD.evieext?=	build

BUILDLINK_TREE+=	evieext

.if !defined(EVIEEXT_BUILDLINK3_MK)
EVIEEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evieext+=	evieext>=1.0.2
BUILDLINK_PKGSRCDIR.evieext?=	../../x11/evieext
.endif # EVIEEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-evieext
