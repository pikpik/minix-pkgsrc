# $NetBSD: Makefile,v 1.15 2013/02/08 13:22:00 taca Exp $

DISTNAME=	rack-1.5.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rack.github.com/
COMMENT=	Modular Ruby webserver interface
LICENSE=	mit

OVERRIDE_GEMSPEC=	:executables rackup=rackup15 \
			:files bin/rackup=bin/rackup15

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;
	${TEST} -f ${WRKSRC}/bin/rackup15 || \
		${MV} ${WRKSRC}/bin/rackup ${WRKSRC}/bin/rackup15

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
