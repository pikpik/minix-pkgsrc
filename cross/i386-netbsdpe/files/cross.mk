#	$PEACE: cross.mk,v 1.1 2001/01/16 15:20:26 kent Exp $
#	NetBSD: cross.mk,v 1.16 2000/11/09 13:04:55 wiz Exp 

# Shared definitions for building a cross-compile environment.

DISTNAME=		cross-${TARGET_ARCH}-${DISTVERSION}
CATEGORIES+=		cross lang
USE_CROSSBASE=		yes
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

HOMEPAGE?=		http://gcc.gnu.org/

TARGET_DIR=		${PREFIX}/${TARGET_ARCH}
COMMON_DIR=		${PKGSRCDIR}/cross/COMMON
GCC_PLIST_DIR=		files
PLIST_PRE?=		${PKGDIR}/PLIST

pre-install: pre-install-dirs
pre-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}
	${INSTALL_DATA_DIR} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/bin
	${INSTALL_DATA_DIR} ${TARGET_DIR}/include
	${INSTALL_DATA_DIR} ${TARGET_DIR}/lib

.if defined(USE_CROSS_BINUTILS)
BINUTILS_DISTNAME=	binutils-2.9.1
BINUTILS_WRKSRC=	${WRKDIR}/${BINUTILS_DISTNAME}

CROSS_DISTFILES+=	${BINUTILS_DISTNAME}.tar.gz
MASTER_SITES+=		${MASTER_SITE_GNU:=binutils/}
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
DEPENDS+=		cross-binutils-2.9.1.1:../../cross/binutils
PLIST_PRE+=		${COMMON_DIR}/PLIST-binutils

AS_FOR_TARGET=		${BINUTILS_WRKSRC}/gas/as-new
AR_FOR_TARGET=		${WRKDIR}/ar
NM_FOR_TARGET=		${WRKDIR}/nm
RANLIB_FOR_TARGET=	${WRKDIR}/ranlib
LD_FOR_TARGET=		${WRKDIR}/ld

pre-patch: binutils-patch
pre-configure: binutils-configure
do-build: binutils-build
do-install: binutils-install

binutils-patch:
	@for i in ${COMMON_DIR}/patches-binutils/patch-*; do \
		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
	done

BFD64ARG=	--enable-64-bit-bfd

binutils-configure:
	@cd ${BINUTILS_WRKSRC} && ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
		CFLAGS="${CFLAGS}" ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} --host=${MACHINE_GNU_ARCH}--netbsd \
		--target=${TARGET_ARCH} ${BFD64ARG}

binutils-build:
	@cd ${BINUTILS_WRKSRC}/bfd && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} bfd.h
	@cd ${BINUTILS_WRKSRC}/libiberty && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} all
	@cd ${BINUTILS_WRKSRC}/gas && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} as-new
	${TEST} -x ${WRKDIR}/ar || ${LINK.c} -o ${WRKDIR}/ar \
		-DPREFIX=\"${PREFIX}\" \
		-DGNUTARGET=\"${BINUTILS_GNUTARGET}\" \
		${COMMON_DIR}/buwrapper.c
	@cd ${WRKDIR} && \
		${LN} -f ar nm && \
		${LN} -f ar ranlib
	${TEST} -x ${WRKDIR}/ld || ${LINK.c} -o ${WRKDIR}/ld \
		-DPREFIX=\"${PREFIX}\" \
		-DGNUTARGET=\"${BINUTILS_GNUTARGET}\" \
		-DLDEMULATION=\"${BINUTILS_LDEMULATION}\" \
		-DLD_RPATH_LINK=\"${TARGET_DIR}/lib\" \
		${COMMON_DIR}/buwrapper.c

binutils-install:
	${INSTALL_PROGRAM} ${BINUTILS_WRKSRC}/gas/as-new ${TARGET_DIR}/bin/as
	${INSTALL_PROGRAM} ${WRKDIR}/ar ${TARGET_DIR}/bin/ar
	${INSTALL_PROGRAM} ${WRKDIR}/ld ${TARGET_DIR}/bin/ld
	for i in addr2line nm objcopy objdump ranlib size strings strip ${BINUTILS_EXTRAS}; do \
		${LN} -f ${TARGET_DIR}/bin/ar ${TARGET_DIR}/bin/$$i; \
	done
	for i in addr2line ar as ld nm objcopy objdump ranlib size strings strip ${BINUTILS_EXTRAS}; do \
		${LN} -f ${TARGET_DIR}/bin/$$i ${PREFIX}/bin/${TARGET_ARCH}-$$i; \
	done
.endif

.if defined(USE_CROSS_GCC)
GCC_DISTNAME=		gcc-2.95.2
#EGCS_DISTDIR=		releases/${EGCS_DISTNAME}
GCC_INTVERSION=		2.95.2
#EGCS_PATCHBUNDLE=	${EGCS_DISTNAME}-NetBSD-19980104.diff.gz
GCC_WRKSRC=		${WRKDIR}/${GCC_DISTNAME}
GCC_LANGUAGES=		c # add to these below
BUILD_DEPENDS+= autoheader:../../devel/autoconf

.if defined(GCC_NO_RUNTIME) || defined(GCC_FAKE_RUNTIME)
GCC_NO_CXX_RUNTIME=	yes
GCC_NO_F77_RUNTIME=	yes
GCC_NO_OBJC_RUNTIME=	yes
.endif

.if !defined(GCC_NO_CXX)
CXX_CONFIGURE_ARGS+=	--with-gxx-include-dir=${TARGET_DIR}/include/g++
GCC_LANGUAGES+=		c++
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-cxx
.if !defined(GCC_NO_CXX_RUNTIME)
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-cxx-runtime
.endif
.endif

.if !defined(GCC_NO_F77)
GCC_LANGUAGES+=		f77
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-f77
.if !defined(GCC_NO_F77_RUNTIME)
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-f77-runtime
.endif
.endif

.if !defined(GCC_NO_OBJC)
GCC_LANGUAGES+=		objc
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-objc
.if !defined(GCC_NO_OBJC_RUNTIME)
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc-objc-runtime
.endif
.endif

# the main PLIST needs to go last to get the @dirrm's right
PLIST_PRE+=		${GCC_PLIST_DIR}/PLIST-gcc
CROSS_DISTFILES+=	${GCC_DISTNAME}.tar.gz #${EGCS_PATCHBUNDLE}
#MASTER_SITES+=		ftp://egcs.cygnus.com/pub/egcs/${EGCS_DISTDIR}/ \
#			${MASTER_SITE_LOCAL}
USE_GMAKE=		yes

CC_FOR_TARGET=		${GCC_WRKSRC}/gcc/xgcc -B${GCC_WRKSRC}/gcc/ ${CFLAGS_FOR_TARGET}
CXX_FOR_TARGET=		${CC_FOR_TARGET}

GCC_MAKE_FLAGS=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
			CC_FOR_TARGET="${CC_FOR_TARGET}" \
			GCC_FOR_TARGET="${CC_FOR_TARGET}" \
			CXX_FOR_TARGET="${CXX_FOR_TARGET}" \
			AS_FOR_TARGET="${AS_FOR_TARGET}" \
			AR_FOR_TARGET="${AR_FOR_TARGET}" \
			NM_FOR_TARGET="${NM_FOR_TARGET}" \
			RANLIB_FOR_TARGET="${RANLIB_FOR_TARGET}" \
			LDFLAGS_FOR_TARGET="${LDFLAGS_FOR_TARGET}" \
			LANGUAGES="${GCC_LANGUAGES}" \
			INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"
GCC_MAKE=		${SETENV} ${MAKE_ENV} \
	                ${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS}

.if defined(GCC_FAKE_RUNTIME)
SYS_INCLUDE=		${WRKDIR}/include
.endif
.if defined(SYS_INCLUDE)
CFLAGS_FOR_TARGET+=	-idirafter ${SYS_INCLUDE}
GCC_MAKE_FLAGS+=	SYSTEM_HEADER_DIR="${SYS_INCLUDE}"
.endif
.if defined(SYS_LIB)
LDFLAGS_FOR_TARGET+=	-L${SYS_LIB}
.endif

#pre-patch: gcc-patch
pre-configure: gcc-configure
do-build: gcc-build
do-install: gcc-install

#gcc-patch:
#	@${GZCAT} ${_DISTDIR}/${EGCS_PATCHBUNDLE} | \
#		${PATCH} -d ${EGCS_WRKSRC} --forward --quiet -E
#	@for i in ${COMMON_DIR}/patches-egcs/patch-*; do \
#		${PATCH} -d ${EGCS_WRKSRC} --forward --quiet -E < $$i; \
#	done

gcc-configure:
	@cd ${GCC_WRKSRC} && ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		./configure --prefix=${PREFIX} \
		--host=${MACHINE_GNU_ARCH}--netbsd  --target=${TARGET_ARCH} \
		${GCC_CONFIGURE_ARGS} ${CXX_CONFIGURE_ARGS}
.if defined(GCC_FAKE_RUNTIME)
	@${MKDIR} ${SYS_INCLUDE} ${SYS_INCLUDE}/machine ${SYS_INCLUDE}/sys
	@cd ${SYS_INCLUDE} && ${TOUCH} ${TOUCH_FLAGS} machine/ansi.h \
		sys/time.h stdlib.h unistd.h
.endif

gcc-build:
	@${LN} -sf ${AS_FOR_TARGET} ${GCC_WRKSRC}/gcc/as
	@${LN} -sf ${LD_FOR_TARGET} ${GCC_WRKSRC}/gcc/ld
	@cd ${GCC_WRKSRC} && make all-libiberty
	@cd ${GCC_WRKSRC}/gcc && ${GCC_MAKE} all
.if !defined(GCC_NO_CXX) && !defined(GCC_NO_CXX_RUNTIME)
	@cd ${GCC_WRKSRC} && ${GCC_MAKE} configure-target-libio configure-target-libstdc++ all-target-libio all-target-libstdc++
.endif
.if !defined(GCC_NO_F77) && !defined(GCC_NO_F77_RUNTIME)
	@cd ${GCC_WRKSRC} && ${GCC_MAKE} configure-target-libf2c all-target-libf2c
.endif
.if !defined(GCC_NO_OBJC) && !defined(GCC_NO_OBJC_RUNTIME)
	@cd ${GCC_WRKSRC}/gcc && ${GCC_MAKE} objc-runtime
.endif

gcc-install:
	@cd ${GCC_WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${GCC_MAKE_FLAGS} \
		install-common install-headers install-libgcc install-driver
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/gcc-lib/${TARGET_ARCH}/${GCC_INTVERSION}
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-gcc ${PREFIX}/bin/${TARGET_ARCH}-cc
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-gcc ${TARGET_DIR}/bin/cc
	${RM} ${PREFIX}/bin/${TARGET_ARCH}-gcj # install-driver installs gcj but we need not it
.if !defined(GCC_NO_F77)
.if !defined(GCC_NO_F77_RUNTIME)
	@cd ${GCC_WRKSRC} && ${GCC_MAKE} install-target-libf2c
.endif
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-g77 ${PREFIX}/bin/${TARGET_ARCH}-f77
	${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-g77 ${PREFIX}/bin/${TARGET_ARCH}-fort77
	for file in f77 fort77 g77; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
.endif
.if !defined(GCC_NO_CXX)
.if !defined(GCC_NO_CXX_RUNTIME)
	@${MKDIR} ${TARGET_DIR}/include/g++/std
	@cd ${GCC_WRKSRC} && ${GCC_MAKE} install-target-libstdc++
.endif
	for file in c++ c++filt g++; do \
		${LN} -f ${PREFIX}/bin/${TARGET_ARCH}-$$file ${TARGET_DIR}/bin/$$file; \
	done
.endif
	@${RMDIR} -p ${PREFIX}/info 2>/dev/null || ${TRUE}
	@${RMDIR} -p ${PREFIX}/man/man1 2>/dev/null || ${TRUE}
.endif

.if defined(CROSS_DISTFILES)
DISTFILES+=		${CROSS_DISTFILES}
.if defined(EXTRACT_ONLY)
EXTRACT_ONLY+=		${CROSS_DISTFILES:N*.diff.gz}
.else
EXTRACT_ONLY=		${DISTFILES:N*.diff.gz}
.endif
.endif

.if defined(SYS_INCLUDE) && !defined(GCC_FAKE_RUNTIME)
pre-install: pre-install-includes
pre-install-includes:
	cd ${SYS_INCLUDE} && ${PAX} -rw . ${TARGET_DIR}/include
.endif

.if defined(SYS_LIB)
pre-install: pre-install-lib
pre-install-lib:
	cd ${SYS_LIB} && ${PAX} -rw . ${TARGET_DIR}/lib
.endif

post-install: post-install-plist
post-install-plist:
	@${SED} -e 's|$${TARGET_ARCH}|${TARGET_ARCH}|' \
		-e 's|$${GCC_INTVERSION}|${GCC_INTVERSION}|' \
		${PLIST_PRE} >${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/bin' >>${PLIST_SRC}
	@${ECHO} '@exec mkdir -p ${TARGET_ARCH}/include' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/include' >>${PLIST_SRC}
	@${ECHO} '@exec mkdir -p ${TARGET_ARCH}/lib' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}/lib' >>${PLIST_SRC}
	@${ECHO} '@dirrm ${TARGET_ARCH}' >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

EXTRACT_BEFORE_ARGS:=	-X ${COMMON_DIR}/exclude ${EXTRACT_BEFORE_ARGS}
