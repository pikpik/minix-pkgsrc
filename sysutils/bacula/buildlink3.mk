# $NetBSD$

BUILDLINK_TREE+=	bacula

.if !defined(BACULA_BUILDLINK3_MK)
BACULA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bacula+=	{bacula,bacula-clientonly}>=3.0.1nb1
BUILDLINK_PKGSRCDIR.bacula?=	../../sysutils/bacula
.endif	# BACULA_BUILDLINK3_MK

BUILDLINK_TREE+=	-bacula
