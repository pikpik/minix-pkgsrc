# $NetBSD: Makefile,v 1.1.1.1 2003/08/31 09:37:51 cjep Exp $
#

DISTNAME=	bsdgrep-200308311112
PKGNAME=	bsdgrep-devel-20030831
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
