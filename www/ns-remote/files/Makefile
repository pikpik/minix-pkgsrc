# $NetBSD$
#
# Very simple Makefile used to compile Netscape's ns-remote program
#

PROG	= ns-remote
X11BASE?= /usr/X11R6

all:	${PROG}

${PROG}:	remote.c
	${CC} ${CFLAGS} -o ${PROG} remote.c -DSTANDALONE -I${X11BASE}/include -L${X11BASE}/lib -lXmu -lX11

clean:
	rm ${PROG}
