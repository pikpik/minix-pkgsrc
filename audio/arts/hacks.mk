$NetBSD$

.include "../../mk/bsd.prefs.mk"

# Work round an ICE with GCC 3.3 on sparc
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
PKG_HACKS+=	sparc-gcc33-ice
GCC_REQD+=	3.4
.endif
