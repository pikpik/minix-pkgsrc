# $NetBSD: buildlink3.mk,v 1.24 2006/07/08 23:11:05 jlam Exp $

BUILDLINK_TREE+=	linux-pam

.if !defined(LINUX_PAM_BUILDLINK3_MK)
LINUX_PAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linux-pam+=		PAM>=0.75
BUILDLINK_ABI_DEPENDS.linux-pam+=	PAM>=0.77nb5
BUILDLINK_PKGSRCDIR.linux-pam?=		../../security/PAM

.include "../../mk/dlopen.buildlink3.mk"
.endif # LINUX_PAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-linux-pam
