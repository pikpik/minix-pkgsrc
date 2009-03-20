# $NetBSD: buildlink3.mk,v 1.14 2008/10/13 22:32:54 bad Exp $

BUILDLINK_TREE+=	nessus-libraries

.if !defined(NESSUS_LIBRARIES_BUILDLINK3_MK)
NESSUS_LIBRARIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nessus-libraries+=	nessus-libraries>=2.2.11
BUILDLINK_ABI_DEPENDS.nessus-libraries?=	nessus-libraries>=2.2.11nb1
BUILDLINK_PKGSRCDIR.nessus-libraries?=	../../security/nessus-libraries

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # NESSUS_LIBRARIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-nessus-libraries
