# $NetBSD: buildlink3.mk,v 1.1 2008/11/06 07:50:56 bjs Exp $

BUILDLINK_TREE+=	see

.if !defined(SEE_BUILDLINK3_MK)
SEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.see+=	see>=3.0.1376
BUILDLINK_PKGSRCDIR.see?=	../../lang/see

.include "../../devel/readline/buildlink3.mk"
.endif # SEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-see
