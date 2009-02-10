# $NetBSD: Makefile,v 1.8 2005/11/07 20:31:56 tv Exp $

DISTNAME=	newmail-1.0.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ugh.net.au/pub/unix/newmail/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Program to check multiple local mailboxes for new mail

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/newmail

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
