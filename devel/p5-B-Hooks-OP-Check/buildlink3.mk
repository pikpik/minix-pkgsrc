# $NetBSD: buildlink3.mk,v 1.1 2008/11/02 23:30:34 he Exp $

BUILDLINK_DEPMETHOD.p5-B-Hooks-OP-Check?=	build

BUILDLINK_TREE+=	p5-B-Hooks-OP-Check

.if !defined(P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK)
P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.12nb1
BUILDLINK_PKGSRCDIR.p5-B-Hooks-OP-Check?=	../../devel/p5-B-Hooks-OP-Check
.endif # P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-OP-Check
