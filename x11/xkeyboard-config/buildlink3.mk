# $NetBSD$

BUILDLINK_TREE+=				xkeyboard-config

.if !defined(XKEYBOARD_CONFIG_BUILDLINK3_MK)
XKEYBOARD_CONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xkeyboard-config+=	xkeyboard-config>=1.9
BUILDLINK_PKGSRCDIR.xkeyboard-config?=		../../x11/xkeyboard-config
BUILDLINK_DEPMETHOD.xkeyboard-config?=		build

.endif	# XKEYBOARD_CONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-xkeyboard-config
