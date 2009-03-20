# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/15 21:29:14 jmcneill Exp $

BUILDLINK_TREE+=	libgamin

.if !defined(LIBGAMIN_BUILDLINK3_MK)
LIBGAMIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgamin+=	libgamin>=0.1.10
BUILDLINK_PKGSRCDIR.libgamin?=	../../sysutils/libgamin
.endif # LIBGAMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgamin
