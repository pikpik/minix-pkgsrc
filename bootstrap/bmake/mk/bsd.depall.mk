#	$NetBSD: bsd.depall.mk,v 1.1.1.1 2002/09/19 10:38:19 agc Exp $

dependall: realdepend .MAKE
	@cd ${.CURDIR}; \
	${MAKE} realall
