# $NetBSD$

PKGNAME=	${RUBY_PKGNAMEPREFIX}DBI-${VERSION}
COMMENT=	DBI for ruby

do-configure:
	cd ${WRKSRC}; ${RUBY} setup.rb config --with=dbi

.include "../../databases/ruby-DBI/Makefile.common"
