# $NetBSD: Makefile,v 1.2 2005/04/10 04:15:44 minskim Exp $

DISTNAME=	actionmailer-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5170/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://am.rubyonrails.org/
COMMENT=	Ruby framework for designing email-service layers

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=1.9.1:../../www/ruby-actionpack

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/action_mailer
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/action_mailer

.include "../../mk/bsd.pkg.mk"
