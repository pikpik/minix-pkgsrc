# $NetBSD$

PGINCLUDE=@PREFIX@/include/pgsql

.c.o:
	cc -I${PGINCLUDE} -Wall -fpic -c $<

all: dewey_cmp.so

dewey_cmp.so: dewey_cmp.o
	cc -shared -o dewey_cmp.so dewey_cmp.o
