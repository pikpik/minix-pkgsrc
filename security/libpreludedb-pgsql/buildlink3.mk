# $NetBSD$

BUILDLINK_TREE+=	libpreludedb-pgsql

.if !defined(LIBPRELUDEDB_PGSQL_BUILDLINK3_MK)
LIBPRELUDEDB_PGSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-pgsql+=	libpreludedb-pgsql>=0.9.15.3
BUILDLINK_PKGSRCDIR.libpreludedb-pgsql?=	../../security/libpreludedb-pgsql

.endif	# LIBPRELUDEDB_PGSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-pgsql
