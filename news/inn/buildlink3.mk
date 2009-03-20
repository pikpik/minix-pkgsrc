# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_TREE+=	inn

.if !defined(INN_BUILDLINK3_MK)
INN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inn+=	inn>=2.3.4
BUILDLINK_PKGSRCDIR.inn?=	../../news/inn
.endif # INN_BUILDLINK3_MK

BUILDLINK_TREE+=	-inn
