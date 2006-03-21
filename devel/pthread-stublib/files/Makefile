# $NetBSD$

all: libpthstub.la

libpthstub.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?

install:
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthstub.la \
		${PREFIX}/lib
