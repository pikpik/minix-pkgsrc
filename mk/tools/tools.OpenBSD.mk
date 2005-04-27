# $NetBSD$
#
# System-supplied tools for the OpenBSD operating system.

PLATFORM_TOOL.awk?=		/usr/bin/awk
PLATFORM_TOOL.basename?=	/usr/bin/basename
PLATFORM_TOOL.cat?=		/bin/cat
PLATFORM_TOOL.chgrp?=		/usr/bin/chgrp
PLATFORM_TOOL.chmod?=		/bin/chmod
PLATFORM_TOOL.chown?=		/usr/sbin/chown
PLATFORM_TOOL.cmp?=		/usr/bin/cmp
PLATFORM_TOOL.cp?=		/bin/cp
PLATFORM_TOOL.cut?=		/usr/bin/cut
PLATFORM_TOOL.date?=		/bin/date
PLATFORM_TOOL.dirname?=		/usr/bin/dirname
PLATFORM_TOOL.echo?=		echo			# shell builtin
PLATFORM_TOOL.egrep?=		/usr/bin/egrep
PLATFORM_TOOL.env?=		/usr/bin/env
PLATFORM_TOOL.expr?=		/bin/expr
PLATFORM_TOOL.false?=		false			# shell builtin
PLATFORM_TOOL.fgrep?=		/usr/bin/fgrep
PLATFORM_TOOL.file?=		/usr/bin/file
PLATFORM_TOOL.find?=		/usr/bin/find
PLATFORM_TOOL.grep?=		/usr/bin/grep
.if exists(/bin/tar)
PLATFORM_TOOL.gtar?=		/bin/tar
.elif exists(/usr/bin/tar)
PLATFORM_TOOL.gtar?=		/usr/bin/tar
.endif
PLATFORM_TOOL.gunzip?=		/usr/bin/gunzip -f
PLATFORM_TOOL.gzcat?=		/usr/bin/gzcat
PLATFORM_TOOL.gzip?=		/usr/bin/gzip -nf ${GZIP}
PLATFORM_TOOL.head?=		/usr/bin/head
PLATFORM_TOOL.hostname?=	/bin/hostname
PLATFORM_TOOL.id?=		/usr/bin/id
PLATFORM_TOOL.ln?=		/bin/ln
PLATFORM_TOOL.ls?=		/bin/ls
PLATFORM_TOOL.m4?=		/usr/bin/m4
PLATFORM_TOOL.mkdir?=		/bin/mkdir -p
PLATFORM_TOOL.mtree?=		/usr/sbin/mtree
PLATFORM_TOOL.mv?=		/bin/mv
PLATFORM_TOOL.nice?=		/usr/bin/nice
PLATFORM_TOOL.patch?=		/usr/bin/patch
PLATFORM_TOOL.pwd?=		/bin/pwd
PLATFORM_TOOL.rm?=		/bin/rm
PLATFORM_TOOL.rmdir?=		/bin/rmdir
PLATFORM_TOOL.sed?=		/usr/bin/sed
PLATFORM_TOOL.sh?=		/bin/sh
PLATFORM_TOOL.sort?=		/usr/bin/sort
PLATFORM_TOOL.tail?=		/usr/bin/tail
PLATFORM_TOOL.tee?=		/usr/bin/tee
PLATFORM_TOOL.test?=		test			# shell builtin
PLATFORM_TOOL.touch?=		/usr/bin/touch
PLATFORM_TOOL.tr?=		/usr/bin/tr
PLATFORM_TOOL.true?=		true			# shell builtin
PLATFORM_TOOL.tsort?=		/usr/bin/tsort
PLATFORM_TOOL.wc?=		/usr/bin/wc
PLATFORM_TOOL.xargs?=		/usr/bin/xargs
