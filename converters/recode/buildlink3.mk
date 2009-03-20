# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_TREE+=	recode

.if !defined(RECODE_BUILDLINK3_MK)
RECODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.recode+=	recode>=3.6nb1
BUILDLINK_ABI_DEPENDS.recode+=	recode>=3.6nb3
BUILDLINK_PKGSRCDIR.recode?=	../../converters/recode

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # RECODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-recode
