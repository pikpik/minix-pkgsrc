# $NetBSD: buildlink3.mk,v 1.7 2008/02/20 09:56:44 xtraeme Exp $

BUILDLINK_TREE+=	libmpeg3

.if !defined(LIBMPEG3_BUILDLINK3_MK)
LIBMPEG3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpeg3+=	libmpeg3>=1.3nb4
BUILDLINK_ABI_DEPENDS.libmpeg3?=	libmpeg3>=1.3nb6
BUILDLINK_PKGSRCDIR.libmpeg3?=		../../multimedia/libmpeg3

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBMPEG3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpeg3
