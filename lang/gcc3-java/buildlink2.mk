# $NetBSD$

.if !defined(GCC3JAVA_BUILDLINK2_MK)
GCC3JAVA_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.endif
BUILDLINK_PACKAGES+=		gcc3java
BUILDLINK_DEPENDS.gcc3java?=	gcc3${GCC3_PKGMODIF}-java>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3java?=	../../lang/gcc3-java

# Packages that link against gcc shared libraries need a full
# dependency.
#
.if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3java+=	full
.else
BUILDLINK_DEPMETHOD.gcc3java?=	build
.endif

BUILDLINK_PREFIX.gcc3java=	${LOCALBASE}
BUILDLINK_WRAPPER_ENV+=	\
	COMPILER_PATH="${BUILDLINK_DIR}/bin"; export COMPILER_PATH

BUILDLINK_FILES.gcc3java=	${_GCC_SUBPREFIX}lib/gcc-lib/*/*/include/java/*
BUILDLINK_FILES.gcc3java+=	${_GCC_SUBPREFIX}/lib/libjava.*

BUILDLINK_TARGETS+=	gcc3java-buildlink

gcc3java-buildlink: _BUILDLINK_USE

.endif	# GCC3JAVA_BUILDLINK2_MK
