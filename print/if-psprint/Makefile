# $NetBSD: Makefile,v 1.3 2000/04/10 06:16:52 tron Exp $
#

DISTNAME=		if-psprint-1.0
CATEGORIES=		print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		abs@netbsd.org

DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	enscript-[0-9]*:../../print/enscript

USE_PERL5=		YES

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		< ${FILESDIR}/if-psprint.pl		\
		> ${WRKSRC}/if-psprint

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/if-psprint ${PREFIX}/libexec/if-psprint

.include "../../mk/bsd.pkg.mk"
