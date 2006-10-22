# $NetBSD$
#

.PATH: ../ld

PROG=	as86
SRCS=	as.c assemble.c error.c express.c genbin.c genlist.c genobj.c	\
	gensym.c macro.c mops.c pops.c readsrc.c scan.c table.c		\
	typeconv.c
WARNS=	0

.include <bsd.prog.mk>
