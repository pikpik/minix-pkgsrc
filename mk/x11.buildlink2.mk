# $NetBSD$

.if !defined(X11_BUILDLINK2_MK)
X11_BUILDLINK2_MK=	# defined

USE_X11=	# defined
USE_X11_LINKS=	no

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin)
.  include "../../pkgtools/x11-links/openwin.buildlink2.mk"
.else
.  include "../../pkgtools/x11-links/xfree.buildlink2.mk"
.endif

.endif	# X11_BUILDLINK2_MK
