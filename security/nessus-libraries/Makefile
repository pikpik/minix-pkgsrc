# $NetBSD: Makefile,v 1.21 2004/11/02 00:01:56 adrianp Exp $

.include 	"../nessus/Makefile.common"

DISTNAME=	nessus-libraries-${VERS}
COMMENT=	Libs required by the Nessus Network security scanner

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
			--with-ssl=${BUILDLINK_PREFIX.openssl} \
			--localstatedir=${VARBASE}
CONFIGURE_ENV+=		CPP="${CPP}"

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
