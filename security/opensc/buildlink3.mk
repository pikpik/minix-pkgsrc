# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/02/26 10:50:05 hasso Exp $

BUILDLINK_TREE+=	opensc

.if !defined(OPENSC_BUILDLINK3_MK)
OPENSC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensc+=	opensc>=0.11.5
BUILDLINK_PKGSRCDIR.opensc?=	../../security/opensc
pkgbase := opensc
.include "../../mk/pkg-build-options.mk"

.include "../../devel/libltdl/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.opensc:Mopenct)
.include "../../security/openct/buildlink3.mk"
.endif
.endif # OPENSC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensc
