# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:45 jlam Exp $

BUILDLINK_TREE+=	libntlm

.if !defined(LIBNTLM_BUILDLINK3_MK)
LIBNTLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libntlm+=	libntlm>=0.3.2
BUILDLINK_ABI_DEPENDS.libntlm+=	libntlm>=0.3.6nb1
BUILDLINK_PKGSRCDIR.libntlm?=	../../devel/libntlm
.endif # LIBNTLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libntlm
