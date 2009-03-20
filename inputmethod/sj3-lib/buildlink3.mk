# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_TREE+=	sj3-lib

.if !defined(SJ3_LIB_BUILDLINK3_MK)
SJ3_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sj3-lib+=	sj3-lib>=2.0.1.20nb1
BUILDLINK_PKGSRCDIR.sj3-lib?=	../../inputmethod/sj3-lib
BUILDLINK_DEPMETHOD.sj3-lib?=	build
.endif # SJ3_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-sj3-lib
