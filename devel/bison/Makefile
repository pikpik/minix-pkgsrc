#	$NetBSD$

DISTNAME=	bison-1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!=		uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=	yes
MAN1=		bison.1

.include <bsd.port.mk>
