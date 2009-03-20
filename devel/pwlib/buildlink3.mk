# $NetBSD: buildlink3.mk,v 1.14 2008/01/18 05:14:38 tnn Exp $

BUILDLINK_TREE+=	pwlib

.if !defined(PWLIB_BUILDLINK3_MK)
PWLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pwlib+=	pwlib>=1.8.3nb1
BUILDLINK_ABI_DEPENDS.pwlib?=	pwlib>=1.8.3nb7
BUILDLINK_PKGSRCDIR.pwlib?=	../../devel/pwlib

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # PWLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pwlib
