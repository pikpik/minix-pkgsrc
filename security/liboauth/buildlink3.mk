# $NetBSD$

BUILDLINK_TREE+=	liboauth

.if !defined(LIBOAUTH_BUILDLINK3_MK)
LIBOAUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth+=	liboauth>=0.8.9
BUILDLINK_PKGSRCDIR.liboauth?=	../../security/liboath

.endif	# LIBOAUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth
