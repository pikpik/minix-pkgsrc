# $NetBSD: Makefile,v 1.60 2006/02/05 23:08:17 joerg Exp $
#

PKGREVISION=		6

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-esd

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	CDAUDIO="@comment "
.else
PLIST_SUBST+=	CDAUDIO=""
.endif

.include "../../mk/bsd.pkg.mk"
