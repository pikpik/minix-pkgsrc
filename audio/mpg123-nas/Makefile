# $NetBSD: Makefile,v 1.22 2010/02/01 01:16:24 joerg Exp $


MPG123_MODULE=	nas

NOT_FOR_COMPILER=	sunpro
ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-* \
			SunOS-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
