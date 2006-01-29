# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	perl python

.include "../../mk/bsd.options.mk"

###
### Whether to build with the perl and python plugins
###
###       python is needed for prewikka
###

.if !empty(PKG_OPTIONS:Mperl)
USE_PERL=		run
CONFIGURE_ARGS+=	--enable-perl
REPLACE_PERL+=		bindings/perl/Makefile.PL
.else
CONFIGURE_ARGS+=	--disable-perl
.endif
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PY_PATCHPLIST=		yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
