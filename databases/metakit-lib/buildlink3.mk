# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:40 jlam Exp $

BUILDLINK_TREE+=	metakit-lib

.if !defined(METAKIT_LIB_BUILDLINK3_MK)
METAKIT_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metakit-lib+=	metakit-lib>=2.4.8
BUILDLINK_ABI_DEPENDS.metakit-lib+=	metakit-lib>=2.4.9.3nb1
BUILDLINK_PKGSRCDIR.metakit-lib?=	../../databases/metakit-lib
.endif # METAKIT_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-metakit-lib
