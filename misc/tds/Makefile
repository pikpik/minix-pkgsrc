# $NetBSD: Makefile,v 1.3 2001/02/17 18:09:26 wiz Exp $
#

DISTNAME=	tds-1.4.2
CATEGORIES=	misc www japanese
MASTER_SITES=	http://tds.dive-in.to/dist/stable/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://tds.dive-in.to/
COMMENT=	web diary system

USE_PERL=	YES
GNU_CONFIGURE=	YES

NO_BUILD=	YES

post-patch:
	@${FIND} ${WRKSRC} -type f -name '*.orig' | xargs ${RM} -f

.include "../../mk/bsd.pkg.mk"
