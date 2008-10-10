# $NetBSD: Makefile,v 1.29 2008/07/14 12:56:12 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include 	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-libraries-${VERS}
COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries

USE_TOOLS+=		bison lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nessuspcap
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		CPP=${CPP:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
