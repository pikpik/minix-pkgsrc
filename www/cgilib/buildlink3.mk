# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_TREE+=	cgilib

.if !defined(CGILIB_BUILDLINK3_MK)
CGILIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgilib+=	cgilib>=0.5nb1
BUILDLINK_ABI_DEPENDS.cgilib+=	cgilib>=0.5nb2
BUILDLINK_PKGSRCDIR.cgilib?=	../../www/cgilib
.endif # CGILIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgilib
