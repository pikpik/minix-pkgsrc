# $NetBSD$
#

.if !defined(_PLONE_PRODUCT_MK)
_PLONE_PRODUCT_MK=	# defined

.include "../../www/plone/ploneversion.mk"

DEPENDS+=	${PLONE_DEPENDENCY}

.endif
