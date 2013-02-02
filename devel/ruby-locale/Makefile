# $NetBSD: Makefile,v 1.2 2010/09/10 05:51:37 taca Exp $

DISTNAME=	locale-2.0.8
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://ruby-gettext.github.com/
COMMENT=	Pure ruby library which provides basic APIs for localization
LICENSE=	ruby-license OR gnu-lgpl-v3

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
