# $NetBSD$
#
# System-supplied tools for the Interix operating system.

PLATFORM_TOOL.awk?=		/usr/contrib/bin/awk
PLATFORM_TOOL.basename?=	/bin/basename
PLATFORM_TOOL.cat?=		/bin/cat
PLATFORM_TOOL.chgrp?=		/bin/chgrp
PLATFORM_TOOL.chmod?=		/bin/chmod
PLATFORM_TOOL.chown?=		/bin/chown
PLATFORM_TOOL.cmp?=		/bin/cmp
PLATFORM_TOOL.cp?=		/bin/cp
PLATFORM_TOOL.cut?=		/bin/cut
PLATFORM_TOOL.date?=		/bin/date
PLATFORM_TOOL.dirname?=		/bin/dirname
PLATFORM_TOOL.echo?=		echo			# shell builtin
PLATFORM_TOOL.egrep?=		/bin/egrep
PLATFORM_TOOL.env?=		/bin/env
PLATFORM_TOOL.expr?=		/bin/expr
PLATFORM_TOOL.false?=		false			# shell builtin
PLATFORM_TOOL.fgrep?=		/bin/fgrep
PLATFORM_TOOL.file?=		/bin/file
PLATFORM_TOOL.find?=		/bin/find
PLATFORM_TOOL.grep?=		/bin/grep
PLATFORM_TOOL.gunzip?=		/usr/contrib/bin/gunzip -f
PLATFORM_TOOL.gzcat?=		/usr/contrib/bin/gunzip -c
PLATFORM_TOOL.gzip?=		/usr/contrib/bin/gzip -nf ${GZIP}
PLATFORM_TOOL.head?=		/bin/head
PLATFORM_TOOL.hostname?=	/bin/hostname
PLATFORM_TOOL.id?=		/bin/id
PLATFORM_TOOL.ln?=		/bin/ln
PLATFORM_TOOL.ls?=		/bin/ls
PLATFORM_TOOL.m4?=		/bin/m4
PLATFORM_TOOL.mkdir?=		/bin/mkdir -p
PLATFORM_TOOL.mv?=		/bin/mv
PLATFORM_TOOL.nice?=		/bin/nice
PLATFORM_TOOL.pwd?=		/bin/pwd
PLATFORM_TOOL.rm?=		/bin/rm
PLATFORM_TOOL.rmdir?=		/bin/rmdir
PLATFORM_TOOL.sh?=		/bin/sh
PLATFORM_TOOL.sort?=		/bin/sort
PLATFORM_TOOL.tail?=		/bin/tail
PLATFORM_TOOL.tee?=		/bin/tee
PLATFORM_TOOL.test?=		/bin/test
PLATFORM_TOOL.touch?=		/bin/touch
PLATFORM_TOOL.tr?=		/bin/tr
PLATFORM_TOOL.true?=		true			# shell builtin
PLATFORM_TOOL.tsort?=		/bin/tsort
PLATFORM_TOOL.wc?=		/bin/wc
PLATFORM_TOOL.xargs?=		/bin/xargs
