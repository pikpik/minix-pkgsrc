# $NetBSD: Makefile,v 1.2 2000/01/13 05:12:16 simonb Exp $
#
# Very simple Makefile used to compile Netscape's ns-remote program
#

PROG	= ns-remote

all:	${PROG}

${PROG}:	remote.c
	${CC} ${CFLAGS} -o ${PROG} remote.c -DSTANDALONE \
	    ${LDFLAGS} -lXmu -lXt -lSM -lICE -lXext -lX11

clean:
	rm ${PROG}
