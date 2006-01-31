# $NetBSD$
#

PERDITION_COMMENT=	LDAP user database module
PERDITION_PKGNAME=	ldap

CONFIGURE_ARGS+=	--with-ldap-includes=${BUILDLINK_PREFIX.openldap}/include
CONFIGURE_ARGS+=	--with-ldap-libs=${BUILDLINK_PREFIX.openldap}/lib

.include "../../databases/openldap/buildlink3.mk"
.include "../perdition/Makefile.common"
