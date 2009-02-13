# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:47 rillig Exp $

DISTNAME=	mrstat-1.20
CATEGORIES=	net
MASTER_SITES=	http://mrstat.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://code.google.com/p/mrstat/
COMMENT=	Track load and number of users on specified hosts

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_DESTDIR_SUPPORT=    destdir

.include "../../mk/bsd.pkg.mk"
