# $NetBSD$

BUILDLINK_TREE+=	libmpdclient

.if !defined(LIBMPDCLIENT_BUILDLINK3_MK)
LIBMPDCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.4
BUILDLINK_PKGSRCDIR.libmpdclient?=	../../audio/libmpdclient
.endif	# LIBMPDCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpdclient
