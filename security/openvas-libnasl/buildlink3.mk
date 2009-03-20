# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/04 01:09:31 adrianp Exp $

BUILDLINK_TREE+=	openvas-libnasl

.if !defined(OPENVAS_LIBNASL_BUILDLINK3_MK)
OPENVAS_LIBNASL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-libnasl+=	openvas-libnasl>=2.0.0
BUILDLINK_PKGSRCDIR.openvas-libnasl?=	../../security/openvas-libnasl
.endif # OPENVAS_LIBNASL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-libnasl
