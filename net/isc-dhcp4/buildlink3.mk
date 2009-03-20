# $NetBSD: buildlink3.mk,v 1.2 2009/01/04 00:56:32 adrianp Exp $

BUILDLINK_TREE+=	isc-dhcp

.if !defined(ISC_DHCP_BUILDLINK3_MK)
ISC_DHCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isc-dhcp+=	isc-dhcp>=4.1.0
BUILDLINK_PKGSRCDIR.isc-dhcp?=	../../net/isc-dhcp4
.endif # ISC_DHCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-isc-dhcp
