# $NetBSD: buildlink3.mk,v 1.2 2008/10/07 13:26:57 kefren Exp $

BUILDLINK_TREE+=	mono-tools

.if !defined(MONO_TOOLS_BUILDLINK3_MK)
MONO_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-tools+=	mono-tools>=2.0
BUILDLINK_PKGSRCDIR.mono-tools?=	../../devel/mono-tools
.endif # MONO_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-tools
