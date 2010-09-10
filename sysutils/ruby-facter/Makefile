# $NetBSD: Makefile,v 1.6 2009/11/17 18:46:15 apb Exp $

DISTNAME=	facter-1.5.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://reductivelabs.com/downloads/gems/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.puppetlabs.com/puppet/related-projects/facter/
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ruby[1-9][0-9]-facter-*

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
