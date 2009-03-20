# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_TREE+=	fcgi

.if !defined(FCGI_BUILDLINK3_MK)
FCGI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fcgi+=	fcgi>=2.2.2nb1
BUILDLINK_ABI_DEPENDS.fcgi+=	fcgi>=2.4.0nb1
BUILDLINK_PKGSRCDIR.fcgi?=	../../www/fcgi
.endif # FCGI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fcgi
