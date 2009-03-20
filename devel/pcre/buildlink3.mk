# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_TREE+=	pcre

.if !defined(PCRE_BUILDLINK3_MK)
PCRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcre+=	pcre>=3.4nb1
BUILDLINK_ABI_DEPENDS.pcre+=	pcre>=6.2
BUILDLINK_PKGSRCDIR.pcre?=	../../devel/pcre
.endif # PCRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcre
