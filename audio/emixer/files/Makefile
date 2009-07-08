#	$NetBSD: Makefile,v 1.6 2004/05/03 17:32:36 minskim Exp $

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lncurses ${LIBOSSAUDIO}

install:
	${BSD_INSTALL_PROGRAM}	emixer	${DESTDIR}${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${DESTDIR}${PREFIX}/share/doc/emixer.readme
