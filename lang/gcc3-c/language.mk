# $NetBSD$

GCC_REQD+=	${GCC_VERSION}

.include "../../lang/gcc3-c/Makefile.common"

BUILDLINK_DEPMETHOD.gcc3c+=	full

pre-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
