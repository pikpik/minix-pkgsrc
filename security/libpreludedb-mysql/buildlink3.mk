# $NetBSD$

BUILDLINK_TREE+=	libpreludedb-mysql

.if !defined(LIBPRELUDEDB_MYSQL_BUILDLINK3_MK)
LIBPRELUDEDB_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-mysql+=	libpreludedb-mysql>=0.9.15.3
BUILDLINK_PKGSRCDIR.libpreludedb-mysql?=	../../security/libpreludedb-mysql

.endif	# LIBPRELUDEDB_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-mysql
