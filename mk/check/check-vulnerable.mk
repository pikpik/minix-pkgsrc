# $NetBSD: check-vulnerable.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $

###########################################################################
### check-vulnerable (PRIVATE, override)
###########################################################################
### check-vulnerable checks for vulnerabilities in the package.  This
### should be overridden per package system flavor.
#
.PHONY: check-vulnerable
.if !target(check-vulnerable)
check-vulnerable:
	@${PHASE_MSG} "Skipping vulnerability checks."
.endif
