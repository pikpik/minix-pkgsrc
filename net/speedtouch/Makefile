# $NetBSD: Makefile,v 1.2 2001/08/06 21:32:39 wiz Exp $
#

DISTNAME=	speedtouch-1.1
CATEGORIES=	net
MASTER_SITES=	http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/
DISTFILES=	${DISTNAME}.tar.bz2 speedmgmt.tar.gz

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.xsproject.org/speedtouch/
COMMENT=	Alcatel SpeedTouch USB ADSL modem driver

DEPENDS+=	userppp-001107:../../net/userppp

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	adsl

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/adsl.sh > ${WRKDIR}/adsl.sh

post-install:
	${INSTALL_DATA} ${WRKDIR}/mgmt/mgmt.o ${PREFIX}/libdata/alcaudsl.sys
	${INSTALL_SCRIPT} ${WRKDIR}/adsl.sh ${PREFIX}/etc/rc.d/adsl

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
