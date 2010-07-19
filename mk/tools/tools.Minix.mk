# $NetBSD: tools.Linux.mk,v 1.47 2010/02/13 08:30:59 obache Exp $
#
# System-supplied tools for the Minix operating system.

#System supplied tools
TOOLS_PLATFORM.[?=		/bin/[
TOOLS_PLATFORM.awk?=		/usr/bin/awk
TOOLS_PLATFORM.basename?=	/usr/bin/basename
TOOLS_PLATFORM.bzcat?=		/usr/bin/bzcat
TOOLS_PLATFORM.cat?=		/bin/cat
TOOLS_PLATFORM.bzip2?=		/usr/bin/bzip2
TOOLS_PLATFORM.chgrp?=		/usr/bin/chgrp
TOOLS_PLATFORM.chmod?=		/usr/bin/chmod
TOOLS_PLATFORM.chown?=		/usr/bin/chown
TOOLS_PLATFORM.cmp?=		/usr/bin/cmp
TOOLS_PLATFORM.cp?=		/bin/cp 
TOOLS_PLATFORM.cut?=		/usr/bin/cut
TOOLS_PLATFORM.date?=		/bin/date
TOOLS_PLATFORM.dirname?=	/usr/bin/dirname
TOOLS_PLATFORM.echo?=		/bin/echo
TOOLS_PLATFORM.env?=		/usr/bin/env
TOOLS_PLATFORM.expr?=		/bin/expr
TOOLS_PLATFORM.false?=		/bin/false
TOOLS_PLATFORM.file?=		/usr/bin/file
TOOLS_PLATFORM.find?=		/usr/bin/find
TOOLS_PLATFORM.head?=		/usr/bin/head
TOOLS_PLATFORM.id?=		/usr/bin/id
TOOLS_PLATFORM.install?=	/bin/install
TOOLS_PLATFORM.ln?=		/bin/ln
TOOLS_PLATFORM.ls?=		/bin/ls
TOOLS_PLATFORM.m4?=		/usr/bin/m4
TOOLS_PLATFORM.mail?=		/usr/bin/mail
TOOLS_PLATFORM.mkdir?=		/usr/bin/mkdir -p
TOOLS_PLATFORM.mv?=		/bin/mv
TOOLS_PLATFORM.nice?=		/usr/bin/nice
TOOLS_PLATFORM.nroff?=		/usr/bin/nroff
TOOLS_PLATFORM.pwd?=		/bin/pwd
TOOLS_PLATFORM.rm?=		/bin/rm
TOOLS_PLATFORM.rmdir?=		/bin/rmdir
TOOLS_PLATFORM.sed?=	/bin/sed
TOOLS_PLATFORM.sh?=		/bin/sh
TOOLS_PLATFORM.sleep?=		/usr/bin/sleep
TOOLS_PLATFORM.strip?=		/usr/bin/strip
TOOLS_PLATFORM.tail?=		/usr/bin/tail
TOOLS_PLATFORM.tar?=		/usr/bin/tar
TOOLS_PLATFORM.bsdtar?=		/usr/bin/bsdtar
TOOLS_PLATFORM.fetch?=		/usr/bin/fetch
TOOLS_PLATFORM.tee?=		/usr/bin/tee
TOOLS_PLATFORM.test?=		/bin/test
TOOLS_PLATFORM.tr?=		/usr/bin/tr
TOOLS_PLATFORM.true?=		/bin/true
TOOLS_PLATFORM.tsort?=		/usr/bin/tsort
TOOLS_PLATFORM.wc?=		/usr/bin/wc
TOOLS_PLATFORM.xargs?=		/usr/bin/xargs
TOOLS_PLATFORM.yacc?=		/usr/bin/yacc
TOOLS_PLATFORM.grep?=		/usr/bin/grep
TOOLS_PLATFORM.egrep?=		/usr/bin/egrep
TOOLS_PLATFORM.fgrep?=		/usr/bin/fgrep
TOOLS_PLATFORM.printf?=		/usr/bin/printf
TOOLS_PLATFORM.touch?=		/usr/bin/touch
TOOLS_PLATFORM.hostname?= /usr/bin/hostname
TOOLS_PLATFORM.patch?=		/usr/bin/patch

# Gnu tools when the Minix tools are known to
# not work in some cases

.if exists(/usr/local/bin/diff)
TOOLS_PLATFORM.diff?=		/usr/local/bin/diff
.else
TOOLS_PLATFORM.diff?=		/usr/bin/diff
.endif

.if exists(/usr/gnu/bin/sort)
TOOLS_PLATFORM.sort?=		/usr/gnu/bin/sort
.else
TOOLS_PLATFORM.sort?=		/usr/bin/sort
.endif

# Temporary hack to fool  configure scripts into using
# gar and gnm with gcc
TOOLS_PLATFORM.ar?=	/usr/gnu/bin/gar
TOOLS_PLATFORM.nm?=	/usr/gnu/bin/gnm

# Other tools if they exist
.if exists(/usr/local/bin/zcat)
TOOLS_PLATFORM.gzcat?=		/usr/local/bin/zcat
.endif
.if exists(/usr/local/bin/bash)
TOOLS_PLATFORM.bash?=		/usr/local/bin/bash
.endif
.if exists(/usr/local/bin/zcat)
TOOLS_PLATFORM.gzcat?=		/usr/local/bin/zcat
.endif

.if exists(/usr/local/bin/bison)
TOOLS_PLATFORM.bison?=		/usr/local/bin/bison
.endif
.if exists(/usr/local/bin/bison)
TOOLS_PLATFORM.bison-yacc?=	/usr/local/bin/bison -y
.endif
.if exists(/usr/local/bin/gawk)
TOOLS_PLATFORM.gawk?=		/usr/local/bin/gawk
.endif
.if exists(/usr/gnu/bin/m4)
TOOLS_PLATFORM.gm4?=		/usr/gnu/bin/m4
.endif
.if exists(/usr/utils/gmake)
TOOLS_PLATFORM.gmake?=		/usr/utils/gmake
.endif
.if exists(/usr/local/bin/groff)
TOOLS_PLATFORM.groff?=		/usr/local/bin/groff
.endif
.if exists(/usr/local/bin/sed)
TOOLS_PLATFORM.gsed?=		/usr/local/bin/sed
.endif
.if exists(/usr/gnu/bin/tar)
TOOLS_PLATFORM.gtar?=		/usr/gnu/bin/tar
.endif
.if exists(/usr/local/bin/gunzip)
TOOLS_PLATFORM.gunzip?=		/usr/local/bin/gunzip -f
.endif
.if exists(/usr/local/bin/gzip)
TOOLS_PLATFORM.gzip?=		/usr/local/bin/gzip -nf ${GZIP}
.endif
.if exists(/usr/bin/flex)
TOOLS_PLATFORM.flex?=		/usr/bin/flex
.endif
.if exists(/usr/local/bin/perl)
TOOLS_PLATFORM.perl?=		/usr/local/bin/perl
.endif
.if exists(/usr/local/bin/unzip)
TOOLS_PLATFORM.unzip?=		/usr/local/bin/unzip
.endif
.if exists(/usr/local/bin/install-info)
TOOLS_PLATFORM.install-info?= /usr/local/bin/install-info
.endif
.if exists(/usr/local/bin/makeinfo)
TOOLS_PLATFORM.makeinfo?= /usr/local/bin/makeinfo
.endif
.if exists(/usr/local/ssl/bin)
TOOLS_PLATFORM.openssl?= /usr/local/ssl/bin
.endif
.if exists(/usr/local/bin/sdiff)
TOOLS_PLATFORM.sdiff?= /usr/local/bin/sdiff
.endif
.if exists(/usr/local/bin/soelim)
TOOLS_PLATFORM.soelim?= /usr/local/bin/soelim
.endif
.if exists(/usr/local/bin/tbl)
TOOLS_PLATFORM.tbl?= /usr/local/bin/tbl
.endif
.if exists(/usr/local/bin/xgettext)
TOOLS_PLATFORM.xgettext?= /usr/local/bin/xgettext
.endif
.if exists(/usr/local/bin/diff3)
TOOLS_PLATFORM.diff3?= /usr/local/bin/diff3
.endif
.if exists(/usr/local/bin/msgfmt)
TOOLS_PLATFORM.msgfmt?= /usr/local/bin/msgfmt
.endif
.if exists(/usr/local/bin/soelim)
TOOLS_PLATFORM.gsoelim?= /usr/local/bin/soelim
.endif
