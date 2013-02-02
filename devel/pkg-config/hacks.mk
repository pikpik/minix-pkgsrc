# $NetBSD: hacks.mk,v 1.7 2012/07/25 13:17:08 obache Exp $

.if !defined(PKGCONFIG_HACKS_MK)
PKGCONFIG_HACKS_MK=	# defined

.if ${OPSYS} == "Darwin"
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	glib/configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.endif

.endif
