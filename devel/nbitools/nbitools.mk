# $NetBSD$
.if !defined(NBITOOLS_MK)
NBITOOLS_MK=	# defined

BUILD_DEPENDS+=	nbitools>=6.3:../../devel/nbitools
EVAL_PREFIX+=	NBITOOLSDIR=nbitools
XMKMF_CMD=	${NBITOOLSDIR}/libexec/itools/xmkmf

.endif	# NBITOOLS_MK
