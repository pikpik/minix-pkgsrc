# $NetBSD: buildlink3.mk,v 1.6 2009/03/18 11:57:15 jmcneill Exp $

BUILDLINK_TREE+=	ptlib

.if !defined(PTLIB_BUILDLINK3_MK)
PTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptlib+=	ptlib>=2.6.1
BUILDLINK_ABI_DEPENDS.ptlib?=	ptlib>=2.6.1
BUILDLINK_PKGSRCDIR.ptlib?=	../../devel/ptlib

.include "../../devel/SDL/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # PTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptlib
