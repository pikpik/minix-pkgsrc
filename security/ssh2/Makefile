# $NetBSD: Makefile,v 1.5 2003/01/28 22:04:08 jlam Exp $
#

PKGNAME=	${DISTNAME:C/ssh-/ssh2-/}
COMMENT=        Secure Shell client and server for V.2 SSH protocol

CONFLICTS=	ssh2-nox11-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x	# be explicit

.include "../../security/ssh2/Makefile.common"
.include "../../mk/bsd.pkg.mk"
