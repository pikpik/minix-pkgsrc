# $NetBSD: Makefile,v 1.1.1.1 2002/03/12 22:19:18 fredette Exp $
#

DISTNAME=       latd-1.18
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=linux-decnet/}

MAINTAINER=	fredette@theory.lcs.mit.edu
HOMEPAGE=	http://theory.lcs.mit.edu/~fredette/latd/index.html
COMMENT=	The linux-decnet project's LAT protocol suite

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-DPREFIX=\"\\\"${PREFIX}\\\"\"

EGDIR=		${PREFIX}/share/examples/latd
CONF_FILES=	${EGDIR}/latd.conf ${PKG_SYSCONFDIR}/latd.conf

.include "../../mk/bsd.pkg.mk"
