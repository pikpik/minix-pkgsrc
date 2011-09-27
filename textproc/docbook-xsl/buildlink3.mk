# $NetBSD$

BUILDLINK_TREE+=	docbook-xsl

.if !defined(DOCBOOK_XSL_BUILDLINK3_MK)
DOCBOOK_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.docbook-xsl+=	docbook-xsl>=1.76.1nb1
BUILDLINK_PKGSRCDIR.docbook-xsl?=	../../textproc/docbook-xsl

BUILDLINK_CONTENTS_FILTER.docbook-xsl=	${EGREP} '/docbook/'
.endif	# DOCBOOK_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-docbook-xsl
