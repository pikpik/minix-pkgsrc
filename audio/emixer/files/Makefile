#	$NetBSD: Makefile,v 1.4 2001/01/07 03:10:50 wiz Exp $

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lncurses -lossaudio

install:
	${BSD_INSTALL_PROGRAM}	emixer	${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${PREFIX}/share/doc/emixer.readme
