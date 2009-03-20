# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_TREE+=	xalan-c

.if !defined(XALAN_C_BUILDLINK3_MK)
XALAN_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xalan-c+=	xalan-c>=1.6nb3
BUILDLINK_ABI_DEPENDS.xalan-c?=	xalan-c>=1.6nb4
BUILDLINK_PKGSRCDIR.xalan-c?=	../../textproc/xalan-c

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.endif # XALAN_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xalan-c
