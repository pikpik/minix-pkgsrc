# $NetBSD: Makefile,v 1.13 2008/11/24 21:48:39 wiz Exp $

.include "../../sysutils/gamin/Makefile.common"
PKGNAME=	${DISTNAME:S/^gamin/lib&/}

CONFIGURE_ARGS+=	--enable-libgamin

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DESTDIR}${DOCDIR}/$$file;	\
	done

.include "../../mk/bsd.pkg.mk"
