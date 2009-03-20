# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:46 jlam Exp $

BUILDLINK_TREE+=	netcdf

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf+=	netcdf>=3.5
BUILDLINK_ABI_DEPENDS.netcdf+=	netcdf>=3.5.0nb2
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf
