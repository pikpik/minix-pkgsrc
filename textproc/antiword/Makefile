# $NetBSD: Makefile,v 1.7 2001/10/17 08:52:03 lukem Exp $
#

DISTNAME=	antiword-0.33
CATEGORIES=	textproc print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	free converter MS Word to text and Postscript converter

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
