# $NetBSD: Makefile,v 1.2 2000/02/14 22:55:31 dmcmahill Exp $
#

DISTNAME=	verilog-0.2
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.2/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html

BUILD_DEPENDS+=	bison:../../devel/bison

CONFLICTS+=	verilog-current

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
