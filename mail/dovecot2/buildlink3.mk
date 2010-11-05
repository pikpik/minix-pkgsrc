# $NetBSD$

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=2.0.6
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot2

pkgbase:=	dovecot
.include "../../mk/pkg-build-options.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
