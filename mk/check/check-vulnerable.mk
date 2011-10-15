# $NetBSD: check-vulnerable.mk,v 1.4 2007/03/09 00:39:54 rillig Exp $
#
# Public targets:
#
# check-vulnerable:
#	Checks for vulnerabilities in the package.
#

.if defined(ALLOW_VULNERABLE_PACKAGES)
check-vulnerable: .PHONY
	@${DO_NADA}
.  else
check-vulnerable: .PHONY _pkgformat-check-vulnerable
	@${DO_NADA}
.endif

# A package format does not need to implement this target, so provide a
# default implementation.
.if !target(_pkgformat-check-vulnerable)
_pkgformat-check-vulnerable:
	@${PHASE_MSG} "Skipping vulnerability checks."
.endif
