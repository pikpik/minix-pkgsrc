# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlite3
PKG_DEFAULT_OPTIONS=	# empty
PKG_SUPPORTED_OPTIONS=	tcl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtcl)
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
PLIST_SUBST+=		TCL_COMMENT=
.  include "../../lang/tcl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUBST+=		TCL_COMMENT="@comment "
.endif
