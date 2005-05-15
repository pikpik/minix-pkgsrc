# $NetBSD$
#
# This file demonstrates that the ${.TARGET} variable must be quoted when
# the target is specified directly.
#
# See also vtarget.
#

all: foo`date`

.PHONY: foo`date`
foo`date`:
	echo ${.TARGET:Q}
