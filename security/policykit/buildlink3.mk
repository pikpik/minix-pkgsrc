# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/22 03:33:38 jmcneill Exp $

BUILDLINK_TREE+=	policykit

.if !defined(POLICYKIT_BUILDLINK3_MK)
POLICYKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.policykit+=	policykit>=0.9
BUILDLINK_PKGSRCDIR.policykit?=	../../security/policykit

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # POLICYKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-policykit
