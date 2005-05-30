# $NetBSD: Makefile,v 1.7 2003/07/17 22:53:40 grant Exp $
#

DISTNAME=	logrot-1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mewburn.net/luke/src/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.mewburn.net/luke/software.html
COMMENT=	Rotate log files in a safe and configurable manner

GNU_CONFIGURE=	YES

OPSYSVARS+=		CONFIGURE_ARGS
CONFIGURE_ARGS.NetBSD+=	--with-pidfile=/var/run/syslogd.pid

.include "../../mk/bsd.pkg.mk"
