# $NetBSD$

DISTNAME=		cowsay-3.02
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.nog.net/pub/tony/cowsay/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.nog.net/~tony/warez/cowsay.shtml

USE_PERL5=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${PREFIX}

.include "../../mk/bsd.pkg.mk"
