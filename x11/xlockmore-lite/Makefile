# $NetBSD: Makefile,v 1.1.1.1 2003/06/30 07:31:19 jlam Exp $

.include "../xlockmore/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-lite-/}
PKGREVISION=	# empty
COMMENT=	"lite" version of xlockmore

CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-gltt
CONFIGURE_ARGS+=	--without-ttf
CONFIGURE_ARGS+=	--without-opengl
CONFIGURE_ARGS+=	--without-mesa
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ENV+=		CXX="${CC}"	# no dependency on libstdc++

.include "../../mk/bsd.pkg.mk"
