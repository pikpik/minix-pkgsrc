# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_TREE+=	cddb-bundle

.if !defined(CDDB_BUNDLE_BUILDLINK3_MK)
CDDB_BUNDLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cddb-bundle+=	cddb-bundle>=0.2
BUILDLINK_ABI_DEPENDS.cddb-bundle?=	cddb-bundle>=0.2nb1
BUILDLINK_PKGSRCDIR.cddb-bundle?=	../../audio/cddb-bundle

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # CDDB_BUNDLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cddb-bundle
