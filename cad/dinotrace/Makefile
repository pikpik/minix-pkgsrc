# $NetBSD: Makefile,v 1.16 2002/04/23 02:08:51 jlam Exp $
#

DISTNAME=	dinotrace-9.1g
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	tool for viewing the output of digital simulators

INFO_FILES=	dinotrace.info

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
