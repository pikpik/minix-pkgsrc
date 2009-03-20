# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/09/12 22:11:28 ahoka Exp $

BUILDLINK_TREE+=	libsigsegv25

.if !defined(LIBSIGSEGV25_BUILDLINK3_MK)
LIBSIGSEGV25_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsigsegv25+=	libsigsegv25>=2.2
BUILDLINK_PKGSRCDIR.libsigsegv25?=	../../devel/libsigsegv25
.endif # LIBSIGSEGV25_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigsegv25
