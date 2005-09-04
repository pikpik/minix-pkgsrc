# $NetBSD: Makefile,v 1.1.1.1 2005/04/10 04:45:59 minskim Exp $

DISTNAME=	activerecord-1.11.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5164/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ar.rubyonrails.org/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport-[0-9]*:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/active_record/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/active_record

.include "../../mk/bsd.pkg.mk"
