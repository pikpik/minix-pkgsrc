# $NetBSD$

all: sq usq

sq: sq.o tr1.o tr2.o sqio.o
	${LINK.c} -o $@ $>

usq: usq.o utr.o
	${LINK.c} -o $@ $>
