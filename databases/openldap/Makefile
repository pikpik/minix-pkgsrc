# $NetBSD:$

DISTNAME=	openldap-release
PKGNAME=	openldap
WRKSRC=		${WRKDIR}/ldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/

# for the moment without threads and thus without slurpd
#DEPENDS+=	../../devel/mit-pthreads

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
