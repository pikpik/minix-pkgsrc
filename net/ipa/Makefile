# $NetBSD: Makefile,v 1.2 2002/04/15 10:51:53 martti Exp $

DISTNAME=	ipa-1.2.7
CATEGORIES=	net sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/

MAINTAINER=	simon@simon.org.ua
HOMEPAGE=	http://www.simon.org.ua/ipa/
COMMENT=	IP accounting software

RESTRICTED=		"Needs to be built uniquely for each host"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_PACKAGE=		${RESTRICTED}

USE_BUILDLINK_ONLY=	# defined
ALL_TARGET=		NetBSD

CFLAGS+=		-DCFGFILE=\\\"${PKG_SYSCONFDIR}/ipa.conf\\\"

CONF_FILES_PERMS=	${PREFIX}/share/examples/ipa/ipa.conf.default	\
			${PKG_SYSCONFDIR}/ipa.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0400
RCD_SCRIPTS=		ipa

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ipa

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
