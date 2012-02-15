PROG=	tg
SRCS=	tg.c
MAN=

LDADD+=	-lnetdriver -lsys -ltimers -lminlib

BINDIR=$(PREFIX)/minixservices
CONFDIR=$(PREFIX)/etc/system.conf.d 

install:
	mkdir -p $(CONFDIR)
	mkdir -p $(BINDIR)
	cp $(PROG) $(BINDIR)/
	cp tg.conf $(CONFDIR)/tg

.include <bsd.prog.mk>
