# $NetBSD$

DISTNAME=	gnus-5.10.2
CATEGORIES=	mail
MASTER_SITES=	http://quimby.gnus.org/gnus/dist/

MAINTAINER=	lha@netbsd.org
HOMEPAGE=	http://www.gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs

#EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus

post-extract:
	${MV} ${WRKSRC}/texi/gnus.texi ${WRKSRC}/texi/ognus.texi

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

