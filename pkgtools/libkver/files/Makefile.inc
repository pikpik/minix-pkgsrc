#	$NetBSD: Makefile.inc,v 1.3 2003/10/27 20:31:42 seb Exp $

.if defined(PREFIX)
# build from pkgsrc
LIBDIR=         ${PREFIX}/lib
BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
.else
# build outside pkgsrc
BINDIR=		/sbin
.endif
