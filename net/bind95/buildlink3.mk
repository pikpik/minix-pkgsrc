# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/06/21 23:15:28 adrianp Exp $

BUILDLINK_TREE+=	bind

.if !defined(BIND_BUILDLINK3_MK)
BIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bind+=	bind>=9.5.0
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind95
.endif # BIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-bind
