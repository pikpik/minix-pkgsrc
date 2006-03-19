# $NetBSD: hacks.mk,v 1.1 2004/11/14 07:24:37 jlam Exp $

.if !defined(COIN_HACKS_MK)
COIN_HACKS_MK=	defined

###
### Compiling Coin on NetBSD with optimization causes an internal
### compiler error.  This is a workaround for PR toolchain/33097.
### Not sure if other platforms have the same issue.
###
.if ${OPSYS} == "NetBSD"
PKG_HACKS+=		optimization
BUILDLINK_TRANSFORM+=   rm:-O[0-9]*
.endif

.endif	# COIN_HACKS_MK
