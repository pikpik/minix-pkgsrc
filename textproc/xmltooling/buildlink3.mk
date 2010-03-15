# $NetBSD$
#

BUILDLINK_TREE+=	xmltooling

.if !defined(XMLTOOLING_C_BUILDLINK3_MK)
XMLTOOLING_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmltooling+=	xmltooling>=1.3.3
BUILDLINK_PKGSRCDIR.xmltooling?=	../../textproc/xmltooling

.endif	# XMLTOOLING_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmltooling
