# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:44 jlam Exp $

BUILDLINK_TREE+=	getopt

.if !defined(LIBGETOPT_BUILDLINK3_MK)
LIBGETOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.getopt+=	libgetopt>=1.3
BUILDLINK_PKGSRCDIR.getopt?=	../../devel/libgetopt
.endif # LIBGETOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-getopt
