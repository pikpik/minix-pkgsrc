# $NetBSD$

DISTNAME=		langspec-2.0.html
PKGNAME=		java-lang-spec-2.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.javasoft.com/docs/specs/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://java.sun.com/docs/books/jls/index.html

NO_WRKSUBDIR=	 	# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/java-lang-spec

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/chars
	cd ${WRKSRC}; ${INSTALL_DATA} *.gif *.html ${HTMLDIR}
	cd ${WRKSRC}/chars; ${INSTALL_DATA} *.gif ${HTMLDIR}/chars

.include "../../mk/bsd.pkg.mk"
