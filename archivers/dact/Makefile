# $NetBSD: Makefile,v 1.17 2006/03/04 21:28:52 jlam Exp $

DISTNAME=	dact-0.8.41
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	Dynamic adaptive compression tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	bin man/man1

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dact

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
