# $NetBSD: buildlink3.mk,v 1.3 2011/08/06 22:21:58 ryoon Exp $

BUILDLINK_TREE+=	libunique3

.if !defined(LIBUNIQUE3_BUILDLINK3_MK)
LIBUNIQUE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunique3+=	libunique3>=3.0.2
BUILDLINK_PKGSRCDIR.libunique3?=	../../x11/libunique3

.endif	# LIBUNIQUE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunique3
