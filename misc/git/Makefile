# $NetBSD: Makefile,v 1.29 2006/04/05 23:01:16 jlam Exp $
PKGNAME=	git-4.9.5
DISTNAME=	gnuit-4.9.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hulubei.net/tudor/git/
COMMENT=	GNU Interactive Tools - a file system browser for UNIX systems

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/gnuit
INFO_FILES=	# PLIST

post-extract:
	${CP} ${WRKSRC}/term/gnuitrc.ansi.in ${WRKSRC}/term/gnuitrc.cons25.in

.include "../../mk/bsd.pkg.mk"
