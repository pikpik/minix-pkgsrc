# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/12 10:56:18 wiz Exp $

BUILDLINK_TREE+=	exempi

.if !defined(EXEMPI_BUILDLINK3_MK)
EXEMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.exempi+=	exempi>=1.99.9
BUILDLINK_PKGSRCDIR.exempi?=	../../devel/exempi

.include "../../textproc/expat/buildlink3.mk"
.endif # EXEMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-exempi
