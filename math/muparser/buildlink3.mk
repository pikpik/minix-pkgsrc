# $NetBSD$

BUILDLINK_TREE+=	muparser

.if !defined(MUPARSER_BUILDLINK3_MK)
MUPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.muparser+=	muparser>=130
BUILDLINK_PKGSRCDIR.muparser?=	../../math/muparser
.endif	# MUPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-muparser
