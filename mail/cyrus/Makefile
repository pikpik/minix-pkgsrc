# $NetBSD$

DISTNAME=	cyrus-imapd-v1.5.14
PKGNAME!=	echo "${DISTNAME}" | sed -e 's/-imapd-v/-/'
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	kim@tac.nyc.ny.us

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-tcl=/usr/local/tcl

.include "../../mk/bsd.pkg.mk"

.if exists(/usr/lib/libkrb.a) && \
    (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS+=	--with-login=krb
.endif
