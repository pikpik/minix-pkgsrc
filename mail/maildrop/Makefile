# $NetBSD$
#

DISTNAME=	maildrop-1.2.2
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/courier/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.flounder.net/~mrsam/maildrop/

.if make(install-run-depends)	# only needed for building
USE_PERL5=	YES
.endif

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-db=db

.include "../../mk/bsd.pkg.mk"
