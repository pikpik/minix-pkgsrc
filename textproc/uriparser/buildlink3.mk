# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/11/08 18:36:14 bjs Exp $

BUILDLINK_TREE+=	uriparser

.if !defined(URIPARSER_BUILDLINK3_MK)
URIPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uriparser+=	uriparser>=0.6.0
BUILDLINK_PKGSRCDIR.uriparser?=	../../textproc/uriparser
.endif # URIPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-uriparser
