# $NetBSD: Makefile,v 1.9 1999/04/13 15:31:06 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace.5.1.1
PKGNAME=	tcptrace-5.1.1
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/5.1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://jarok.cs.ohiou.edu/software/tcptrace/tcptrace.html

WRKSRC=         ${WRKDIR}/tcptrace_5.1.1
GNU_CONFIGURE=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../mk/bsd.pkg.mk"
