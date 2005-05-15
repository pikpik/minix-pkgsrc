# $NetBSD$
#
# This file demonstrates various techniques for quoting variables when
# passing them to the shell.
#

EVIL_STRING?=	"   "

.PHONY: all
all:
	echo ${EVIL_STRING}
	echo ${EVIL_STRING:Q}
	echo "${EVIL_STRING}"
	echo "${EVIL_STRING:Q}"
	echo ${EVIL_STRING:Q}""
	echo x${EVIL_STRING:Q} | sed 1s,.,,
