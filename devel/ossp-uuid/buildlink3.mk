# $NetBSD: buildlink3.mk,v 1.2 2008/07/14 00:02:38 bjs Exp $

BUILDLINK_TREE+=	ossp-uuid

.if !defined(OSSP_UUID_BUILDLINK3_MK)
OSSP_UUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.0
BUILDLINK_ABI_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.2
BUILDLINK_PKGSRCDIR.ossp-uuid?=		../../devel/ossp-uuid
.endif # OSSP_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-uuid
