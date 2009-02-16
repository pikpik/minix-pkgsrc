# $NetBSD: Makefile,v 1.3 2007/06/18 14:45:29 jlam Exp $

PROG=	rmail
MAN=	rmail.8
BINDIR=	@PREFIX@/bin
MANDIR=	@PREFIX@/@PKGMANDIR@

SRCS=	rmail.c
OBJS=	rmail.o

all: ${PROG}

install: all
	@INSTALL_PROGRAM@ ${PROG} ${DESTDIR}${BINDIR}/${PROG}
	@INSTALL_MAN@ ${MAN} ${DESTDIR}${MANDIR}/man8

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ ${OBJS}
