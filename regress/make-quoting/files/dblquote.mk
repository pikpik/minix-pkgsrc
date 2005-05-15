# $NetBSD$
#
# This file demonstrates that quoted strings are interpreted when appying
# the ``modifiers'', not when creating strings by assignment.
#

DBLQUOTE=	"
DBLQUOTE+=	"a   b"
DBLQUOTE+=	"

all:
	echo ${DBLQUOTE:Q}
	echo ${DBLQUOTE:M*:Q}
