# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/12 14:05:17 dillo Exp $

BUILDLINK_TREE+=	wbxml2

.if !defined(WBXML2_BUILDLINK3_MK)
WBXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wbxml2+=	wbxml2>=0.9.2
BUILDLINK_PKGSRCDIR.wbxml2?=	../../textproc/wbxml2

.include "../../textproc/expat/buildlink3.mk"
.endif # WBXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-wbxml2
