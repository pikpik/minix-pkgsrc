# $NetBSD: buildlink3.mk,v 1.6 2007/12/30 14:34:18 obache Exp $

BUILDLINK_TREE+=	pcrexx

.if !defined(PCREXX_BUILDLINK3_MK)
PCREXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcrexx+=	pcre++>=0.9.5
BUILDLINK_PKGSRCDIR.pcrexx?=	../../devel/pcre++

.include "../../devel/pcre/buildlink3.mk"
.endif # PCREXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcrexx
