# $NetBSD$
#

BUILDLINK_TREE+=	npapi-sdk

.if !defined(NPAPI_SDK_BUILDLINK3_MK)
NPAPI_SDK_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.npapi-sdk?=	build
BUILDLINK_API_DEPENDS.npapi-sdk+=	npapi-sdk>=0.27
BUILDLINK_PKGSRCDIR.npapi-sdk?=	../../devel/npapi-sdk
.endif	# NPAPI_SDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-npapi-sdk
