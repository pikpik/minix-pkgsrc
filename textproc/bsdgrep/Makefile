# $NetBSD: Makefile,v 1.1.1.1 2002/11/19 07:15:14 cjep Exp $

DISTNAME=	grep-0.16
PKGNAME=	bsdgrep-0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vocito.com/downloads/software/grep/ \
		ftp://ftp.vocito.com/pub/vocito.com/software/grep/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vocito.com/downloads/software/grep/
COMMENT=	BSD version of grep

post-patch:
	@${CP} ${WRKSRC}/grep.1 ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
