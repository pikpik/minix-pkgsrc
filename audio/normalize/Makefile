# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 09:10:15 lukem Exp $
#

DISTNAME=	normalize-0.7.6
CATEGORIES=	audio
MASTER_SITES=	http://www.cs.columbia.edu/~cvaill/normalize/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.cs.columbia.edu/~cvaill/normalize/
COMMENT=	Wave (.wav) file volume normalizer

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GNU_GETTEXT=YES
CONFIGURE_ARGS+=--without-libiconv-prefix
CONFIGURE_ARGS+=--without-libintl-prefix
#CONFIGURE_ARGS+=--with-audiofile
CONFIGURE_ARGS+=--with-mad

#.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
