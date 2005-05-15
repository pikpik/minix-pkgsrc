# $NetBSD$
#
# This file demonstrates that the ${.TARGET} variable does not have to
# be quoted when the target is specified by a quoted variable.
#

FOO=		a    b `date`

${FOO:Q}:
	echo ${.TARGET}
