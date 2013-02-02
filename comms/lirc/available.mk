# $NetBSD$

.include "../../mk/bsd.prefs.mk"

# At the moment LIRC is available only for Linux.  The following
# condition is here to NOT repeat supported platforms in multiple
# places, i.e. mplayer, xine, xbmc etc.
# Also, have a look at buildlink3.mk.
.if ${OPSYS} == "Linux"
LIRC_AVAILABLE=	yes
.else
LIRC_AVAILABLE=	no
.endif
