# $NetBSD: buildlink3.mk,v 1.8 2006/09/07 08:46:20 wennmach Exp $

BUILDLINK_TREE+=	kth-krb4

.if !defined(KTH_KRB4_BUILDLINK3_MK)
KTH_KRB4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kth-krb4+=	kth-krb4>=1.1.1
BUILDLINK_ABI_DEPENDS.kth-krb4+=	kth-krb4>=1.2.1nb5
BUILDLINK_ABI_DEPENDS.kth-krb4?=	kth-krb4>=1.2.1nb6
BUILDLINK_PKGSRCDIR.kth-krb4?=		../../security/kth-krb4
.endif # KTH_KRB4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kth-krb4
