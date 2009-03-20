# $NetBSD: buildlink3.mk,v 1.1 2008/06/05 19:29:46 drochner Exp $

BUILDLINK_TREE+=	libsmi

.if !defined(LIBSMI_BUILDLINK3_MK)
LIBSMI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsmi+=	libsmi>=0.4.5nb1
BUILDLINK_PKGSRCDIR.libsmi?=	../../devel/libsmi
.endif # LIBSMI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsmi
