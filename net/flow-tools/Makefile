# $NetBSD: Makefile,v 1.7 2001/02/17 18:19:13 wiz Exp $

DISTNAME=	flow-tools-0.59
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.splintered.net/sw/flow-tools/
COMMENT=	Collect and store NetFlow data

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../devel/zlib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
