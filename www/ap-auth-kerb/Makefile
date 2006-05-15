# $NetBSD$

DISTNAME=	mod_auth_kerb-5.0rc7
PKGNAME=	ap-auth-kerb-5.0rc7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=modauthkerb/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://modauthkerb.sourceforge.net/
COMMENT=	Module to allow Apache authentication using Kerberos

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-krb4
USE_TOOLS+=		gmake

APACHE_MODULE=		yes

.include "../../mk/apache.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
