# $NetBSD$
#
# This Makefile fragment is included by packages that use tdb.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TDB_BUILDLINK3_MK:=	${TDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tdb
.endif

.if !empty(TDB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		tdb
BUILDLINK_DEPENDS.tdb+=		tdb>=1.0.6
BUILDLINK_PKGSRCDIR.tdb?=	../../databases/tdb

.endif # TDB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
