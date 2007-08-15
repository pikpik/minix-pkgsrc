# $NetBSD: options.mk,v 1.2 2007/08/13 12:40:57 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=		x11
PKG_SUPPORTED_OPTIONS+=		nox11	# OBSOLETE; remove after pkgsrc-2007Q4
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk motif xaw
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

###
### OBSOLETE section.  Should be removed after pkgsrc-2007Q4.
### The "nox11" option implies removing all of the "x11"-related options.
###
.if !empty(PKG_OPTIONS:Mnox11)
PKG_OPTIONS:=		${PKG_OPTIONS:Nx11:Ngtk:Nmotif:Nxaw}
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated option nox11 used, use option -x11 instead."
.endif

###
### Any of the "toolkit" options implies "x11".
###
.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Xaw X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mgtk) && empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
PKG_OPTIONS+=		xaw
.  endif
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"

# Need libungif>=4.1.0b1 (a bug in 4.1.0 can crash Emacs)
BUILDLINK_API_DEPENDS.libungif+=	libungif>=4.1.0.1
.  include "../../graphics/libungif/buildlink3.mk"

CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
.else
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.endif

###
### Support using Xaw (Lucid) X11 widgets.
###
.if !empty(PKG_OPTIONS:Mxaw)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif
