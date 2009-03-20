# $NetBSD: buildlink3.mk,v 1.1 2007/07/29 21:34:31 seb Exp $

BUILDLINK_DEPMETHOD.flow-tools?=	build

BUILDLINK_TREE+=	flow-tools

.if !defined(FLOW_TOOLS_BUILDLINK3_MK)
FLOW_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flow-tools+=	flow-tools>=0.68nb2
BUILDLINK_PKGSRCDIR.flow-tools?=	../../net/flow-tools
.endif # FLOW_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flow-tools
