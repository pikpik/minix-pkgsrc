# $NetBSD: gcc.buildlink2.mk,v 1.2 2003/07/09 08:25:04 salo Exp $
#
# USE_GCC2
#	If defined, use gcc from lang/gcc.
# USE_GCC3
#	If defined, use gcc3 from lang/gcc3.
#

.if !defined(GCC_BUILDLINK2_MK)
GCC_BUILDLINK2_MK=	# defined

.if defined(USE_GCC3) && empty(PKGPATH:Mlang/gcc3)
.  include "../lang/gcc3/buildlink2.mk"
.elif defined(USE_GCC2) && empty(PKGPATH:Mlang/gcc)
.  include "../lang/gcc/buildlink2.mk"
.endif

.endif	# GCC_BUILDLINK2_MK
