# $NetBSD$
# PHP wrapper, for module builds

.if !defined(PHPEXT_MK)
PHPEXT_MK=	defined

.include "../../lang/php/phpversion.mk"

.if (defined(USE_BUILDLINK3) && empty(USE_BUILDLINK3:M[nN][oO]))
.    include "${PHPPKGSRCDIR}/Makefile.module"
.endif

.endif	# PHPEXT_MK
