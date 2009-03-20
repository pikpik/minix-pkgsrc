# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/28 23:36:39 wiz Exp $

BUILDLINK_TREE+=	qof

.if !defined(QOF_BUILDLINK3_MK)
QOF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qof+=	qof>=0.7.5
BUILDLINK_PKGSRCDIR.qof?=	../../devel/qof

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # QOF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qof
