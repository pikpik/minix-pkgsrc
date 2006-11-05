# $NetBSD$
#
# Conditionally include mk/bsd.prefs.mk, if it wasn't processed already.
#

.if !defined(BSD_PKG_MK)
.include "../../mk/bsd.prefs.mk"
.endif
