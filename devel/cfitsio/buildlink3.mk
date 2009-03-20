# $NetBSD: buildlink3.mk,v 1.1 2008/12/29 10:13:12 markd Exp $

BUILDLINK_TREE+=	cfitsio

.if !defined(CFITSIO_BUILDLINK3_MK)
CFITSIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cfitsio+=	cfitsio>=3.100
BUILDLINK_PKGSRCDIR.cfitsio?=	../../devel/cfitsio
.endif # CFITSIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cfitsio
