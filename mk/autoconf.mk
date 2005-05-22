# $NetBSD: autoconf.mk,v 1.7 2005/05/11 22:17:26 jlam Exp $
#
# makefile fragment for packages that use autoconf
# AUTOCONF_REQD can be set to the minimum version required.
# It adds a build dependency on the appropriate autoconf package
# and sets the following variables:
#	AUTOCONF:	autoconf binary to use
#	AUTORECONF:	autoreconf binary to use
#	AUTOHEADER:	autoheader binary to use
#

.if !defined(AUTOCONF_MK)
AUTOCONF_MK=	# defined

# minimal required version
AUTOCONF_REQD?= 2.50

.include "../../mk/bsd.prefs.mk"

.if empty(AUTOCONF_REQD:M2.1[0-9]*)
USE_TOOLS+=		autoconf
.else
USE_TOOLS+=		autoconf213
.endif

.endif # AUTOCONF_MK
