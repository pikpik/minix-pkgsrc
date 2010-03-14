# $NetBSD: Makefile,v 1.20 2008/08/11 15:21:04 joerg Exp $

MPG123_MODULE=	esd


.include "${.CURDIR}/../../audio/mpg123/Makefile.common"


USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
