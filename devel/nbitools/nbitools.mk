# $NetBSD: nbitools.mk,v 1.1 2002/06/03 09:53:46 sakamoto Exp $
.if !defined(NBITOOLS_MK)
NBITOOLS_MK=	# defined

XMKMF_CMD=	${NBITOOLSDIR}/libexec/itools/xmkmf

.include "../../devel/nbitools/buildlink2.mk"

.endif	# NBITOOLS_MK
