# $NetBSD$

.if !defined(COMPILER_MIPSPRO_MK)
COMPILER_MIPSPRO_MK=	defined

.include "../../mk/bsd.prefs.mk"

MISPROBASE?=	/usr
CC=	${MIPSPROBASE}/bin/cc
CPP=	${MIPSPROBASE}/bin/cc -E
CXX=	${MIPSPROBASE}/bin/CC

CC_VERSION!=	${CC} -V 2>&1 | ${GREP} '^cc'

.endif	# COMPILER_MIPSPRO_MK
