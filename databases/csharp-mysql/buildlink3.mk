# $NetBSD$

BUILDLINK_TREE+=	csharp-mysql

.if !defined(CSHARP_MYSQL_BUILDLINK3_MK)
CSHARP_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.csharp-mysql+=	csharp-mysql>=6.3.5
BUILDLINK_PKGSRCDIR.csharp-mysql?=	../../databases/csharp-mysql
.endif	# CSHARP_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-csharp-mysql
