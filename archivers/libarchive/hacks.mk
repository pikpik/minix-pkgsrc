# $NetBSD$

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:MIRIX*)
CPPFLAGS+=	-Dvfork=fork
CONFIGURE_ENV+=	ac_cv_func_vfork=yes
.endif
