# $NetBSD: Makefile,v 1.2 2004/03/02 21:53:55 kristerw Exp $
#

DISTNAME=	iftop-0.16
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.ex-parrot.com/~pdw/iftop/download/
COMMENT=	Display bandwidth usage on an interface

USE_BUILDLINK2=		yes
USE_NCURSES=		# mvchgat()
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
