# $NetBSD: Makefile,v 1.3 2005/05/22 05:35:32 jlam Exp $

PKGNAME=		postgresql73-plperl-${BASE_VERS}
PKGREVISION=		1
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql73-server>=${BASE_VERS}:../../databases/postgresql73-server


.include "../postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-perl

BUILD_DIRS=		${WRKSRC}/src/pl/plperl
MAKEFILE=		GNUmakefile
PERL5_REQD+=		5.8.0

.include "../postgresql73-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
