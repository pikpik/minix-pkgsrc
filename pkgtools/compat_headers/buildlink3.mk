# $NetBSD: buildlink3.mk,v 1.2 2008/05/25 17:38:37 tnn Exp $

BUILDLINK_TREE+=	compat_headers

.if !defined(COMPAT_HEADERS_BUILDLINK3_MK)
COMPAT_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat_headers+=	compat_headers>=0.2
BUILDLINK_PKGSRCDIR.compat_headers?=	../../pkgtools/compat_headers
BUILDLINK_DEPMETHOD.compat_headers?=	build
.endif # COMPAT_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat_headers
