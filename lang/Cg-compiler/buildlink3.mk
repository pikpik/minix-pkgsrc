# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_TREE+=	Cg-compiler

.if !defined(CG_COMPILER_BUILDLINK3_MK)
CG_COMPILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Cg-compiler+=		Cg-compiler>=1.2.1
BUILDLINK_ABI_DEPENDS.Cg-compiler?=	Cg-compiler>=1.3beta2nb1
BUILDLINK_PKGSRCDIR.Cg-compiler?=	../../lang/Cg-compiler
.endif # CG_COMPILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-Cg-compiler
