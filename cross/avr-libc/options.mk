# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.avr_libc
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS=	doc

.if !empty(PKG_OPTIONS:Mdoc)

PLIST_SRC+=		${.CURDIR}/PLIST.doc

BUILD_DEPENDS+=		doxygen>=1.6.3nb1:../../devel/doxygen
BUILD_DEPENDS+=		transfig-[0-9]*:../../print/transfig
BUILD_DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

CONFIGURE_ARGS+=	--enable-doc
CONFIGURE_ARGS+=	--disable-versioned-doc

post-build:
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE}
	cd ${WRKSRC}/doc/examples/demo && ${GMAKE} dox

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/avr-libc
	for f in Makefile demo.c demo.bin demo.hex demo.pdf \
		demo.srec;\
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/demo/$$f \
			${DESTDIR}${PREFIX}/share/doc/avr-libc/examples/demo; \
	done

.else

CONFIGURE_ARGS+=	--disable-doc

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/LICENSE \
		${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/avr-libc

.endif
