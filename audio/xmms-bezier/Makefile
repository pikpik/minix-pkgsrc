# $NetBSD: Makefile,v 1.6 2003/07/17 21:23:54 grant Exp $
#

DISTNAME=	bezier-0.0.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://yossman.net/~kuroyi/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	OpenGL XMMS plugin

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3= yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

BUILDLINK_TRANSFORM+=	l:MesaGL:GL

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
