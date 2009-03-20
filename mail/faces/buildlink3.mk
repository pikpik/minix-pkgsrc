# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:57 jlam Exp $

BUILDLINK_TREE+=	faces

.if !defined(FACES_BUILDLINK3_MK)
FACES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faces+=	faces>=1.6.1nb1
BUILDLINK_ABI_DEPENDS.faces+=	faces>=1.6.1nb4
BUILDLINK_PKGSRCDIR.faces?=	../../mail/faces
.endif # FACES_BUILDLINK3_MK

BUILDLINK_TREE+=	-faces
