# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/04 01:08:52 adrianp Exp $

BUILDLINK_TREE+=	openvas-libraries

.if !defined(OPENVAS_LIBRARIES_BUILDLINK3_MK)
OPENVAS_LIBRARIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-libraries+=	openvas-libraries>=2.0.0
BUILDLINK_PKGSRCDIR.openvas-libraries?=	../../security/openvas-libraries
.endif # OPENVAS_LIBRARIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-libraries
