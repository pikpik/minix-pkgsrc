PROG=	tg3
SRCS=	tg3.c
MAN=

LDADD+=	-lnetdriver -lsys -ltimers -lminlib

CONFDIR=$(PREFIX)/etc/system.d 

install:
	cp $(PROG) $(PREFIX)/sbin/
	mkdir -p $(CONFDIR)
	cp tg.conf $(CONFDIR)/

.include <bsd.prog.mk>
