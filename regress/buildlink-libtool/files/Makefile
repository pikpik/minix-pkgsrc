# $NetBSD$

.PHONY: all
all: libregress1.la libregress2.la

.SUFFIXES: .lo

.c.lo:
	${LIBTOOL} --mode=compile ${CC} -c $<

libregress1.la: f.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $>				\
		-rpath ${PREFIX}/lib -version-info 0:0

libregress2.la: libregress1.la f.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $> libregress1.la		\
		-rpath ${PREFIX}/lib -version-info 0:0
