# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	libmimedir

.if !defined(LIBMIMEDIR_BUILDLINK3_MK)
LIBMIMEDIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmimedir+=	libmimedir>=0.4nb1
BUILDLINK_PKGSRCDIR.libmimedir?=	../../devel/libmimedir
.endif # LIBMIMEDIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmimedir
