# $NetBSD: buildlink3.mk,v 1.4 2009/03/19 15:50:27 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.1beta16
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
