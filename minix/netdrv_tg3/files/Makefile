PROG=	tg
SRCS=	tg.c
MAN=

LDADD+=	-lnetdriver -lsys -ltimers -lminlib -static

BINDIR=$(PREFIX)/minixservices
CONFDIR=$(PREFIX)/etc/system.conf.d 

install:
	mkdir -p ${DESTDIR}$(CONFDIR)
	mkdir -p ${DESTDIR}$(BINDIR)
	cp $(PROG) ${DESTDIR}$(BINDIR)/
	cp tg.conf ${DESTDIR}$(CONFDIR)/tg

.include <bsd.prog.mk>
