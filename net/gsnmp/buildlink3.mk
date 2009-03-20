# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/10/29 09:48:31 seb Exp $

BUILDLINK_TREE+=	gsnmp

.if !defined(GSNMP_BUILDLINK3_MK)
GSNMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsnmp+=	gsnmp>=0.2.0
BUILDLINK_PKGSRCDIR.gsnmp?=	../../net/gsnmp
.endif # GSNMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsnmp
