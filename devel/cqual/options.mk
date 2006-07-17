# $NetBSD$
#

PKG_SUPPORTED_OPTIONS=		debug
PKG_SUGGESTED_OPTIONS=		# none
PKG_OPTIONS_VAR=		PKG_OPTIONS.cqual

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
pre-configure:
	${ECHO} "Enable debugging" > ${WRKSRC}/TODO-LOCAL
.endif
