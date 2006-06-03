# $NetBSD$

###########################################################################
# check-vulnerable checks for vulnerabilities in the package.  This should
# be overridden per package system flavor.
#
.PHONY: check-vulnerable
.if !target(check-vulnerable)
check-vulnerable:
	@${ECHO_MSG} "${_PKGSRC_IN} *** Skipping vulnerability checks."
.endif
