# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:48 jlam Exp $

BUILDLINK_TREE+=	rpc2

.if !defined(RPC2_BUILDLINK3_MK)
RPC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rpc2+=	rpc2>=1.10
BUILDLINK_ABI_DEPENDS.rpc2+=	rpc2>=1.27nb1
BUILDLINK_PKGSRCDIR.rpc2?=	../../devel/rpc2

.include "../../devel/lwp/buildlink3.mk"
.endif # RPC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-rpc2
