# $NetBSD: Makefile,v 1.1.1.1 2000/04/21 10:57:33 mjl Exp $
#

DISTNAME=	smtpd-2.0
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.obtuse.com/pub/smtpd/

PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.obtuse.com/smtpd.html

SPOOL=		/var/spool/smtpd
MESSAGE_FILE=	${WRKDIR}/MESSAGE

pre-install:
		-${MKDIR} ${SPOOL}/etc
		for f in antirelay_check_rules_example antispam_check_rules.example smtpd_check_rules.example ; do ${INSTALL_DATA} ${WRKSRC}/$$f ${SPOOL}/etc; done
		${CHOWN} -R uucp.mail ${SPOOL}
		${CHMOD} -R g=,o= ${SPOOL}
		${CP} /etc/localtime /etc/resolv.conf ${SPOOL}/etc

post-build:
		${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
			>${MESSAGE_FILE}

.include "../../mk/bsd.pkg.mk"
