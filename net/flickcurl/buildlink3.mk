# $NetBSD$

BUILDLINK_TREE+=	flickcurl

.if !defined(FLICKCURL_BUILDLINK3_MK)
FLICKCURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flickcurl+=	flickcurl>=1.21
BUILDLINK_PKGSRCDIR.flickcurl?=	../../net/flickcurl

.endif	# FLICKCURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-flickcurl
