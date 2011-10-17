# $NetBSD$
#

BUILDLINK_TREE+=	gdbm_compat

.if !defined(GDBM_COMPAT_BUILDLINK3_MK)
GDBM_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm_compat+=	gdbm_compat>=1.9.1
BUILDLINK_PKGSRCDIR.gdbm_compat?=	../../databases/gdbm_compat

.include "../../databases/gdbm/buildlink3.mk"
.endif	# GDBM_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm_compat
