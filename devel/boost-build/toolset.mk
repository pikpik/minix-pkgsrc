# $NetBSD$

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
BOOST_TOOLSET=		gcc
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
BROKEN+=		"Unknown compiler ${PKGSRC_COMPILER} for Boost"
.endif
