# $NetBSD: Makefile,v 1.3 2004/03/16 02:01:11 taca Exp $
# FreeBSD: ports/textproc/ruby-html-parser/Makefile,v 1.6 2000/09/26 08:01:54 knu Exp

DISTNAME=	html-parser-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-html-parser-${VERSION}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/html-parser/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.jin.gr.jp/~nahi/Ruby/html-parser/README.html
COMMENT=	HTML-parser package for Ruby

NO_BUILD=	yes
NO_CONFIGURE=	yes

MODULES=	formatter.rb html-parser.rb sgml-parser.rb
VERSION=	19990912p1

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/html-parser
	${INSTALL_DATA} ${WRKSRC}/README.html ${RUBY_DOCDIR}/html-parser

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
