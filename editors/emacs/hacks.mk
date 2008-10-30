# $NetBSD: hacks.mk,v 1.1 2005/11/07 21:24:37 tv Exp $

###
### Workaround for PR 39778
###
.if !empty(MACHINE_PLATFORM:MNetBSD-4.99.*-x86_64)
pre-build:
	${TOUCH} ${WRKSRC}/leim/quail/tsang-b5.el
.endif
