# $NetBSD: Makefile,v 1.8 2000/07/31 07:37:00 jlam Exp $
#

USE_XPM=		YES

CONFLICTS+=		icewm-gnome-[0-9]*

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"

.include "../../x11/icewm/Makefile.common"
