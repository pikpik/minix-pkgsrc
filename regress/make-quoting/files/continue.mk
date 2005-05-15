# $NetBSD$
#
# This file demonstrates that .for variables that end in a backslash are
# interpreted as line-continuations when they are placed at the end of a
# line.
#

LIST=		a:\ a:\foo.bar

.PHONY: all
all:
.for l in ${LIST}
	echo ${l:Q}
	echo "second line"
.endfor
.for l in ${LIST}
	echo ${l:Q}""
	echo "second line"
.endfor
