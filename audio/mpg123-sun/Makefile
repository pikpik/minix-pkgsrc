# $NetBSD$
#

MPG123_MODULE=	sun
# this is builtin with ../mpg123 on these architectures
NOT_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* SunOS-*-*
NOT_FOR_PLATFORM+=	DragonFly-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
