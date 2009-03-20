# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_TREE+=	libmpd

.if !defined(LIBMPD_BUILDLINK3_MK)
LIBMPD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.12.0
BUILDLINK_PKGSRCDIR.libmpd?=	../../audio/libmpd
.endif # LIBMPD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpd
