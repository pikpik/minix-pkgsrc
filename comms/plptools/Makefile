# $NetBSD: Makefile,v 1.24 2004/04/25 00:36:04 wiz Exp $
#

DISTNAME=	plptools-0.12
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plptools/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://plptools.sourceforge.net/
COMMENT=	FTP-like and NFS-like access tools to talk to the PSION

USE_BUILDLINK3=		YES
USE_GNU_READLINE=	# uses rl_filename_quoting_desired flag
USE_GNU_TOOLS+=		make
USE_LANUGAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-serial=${DEFAULT_SERIAL_DEVICE}
LIBS+=			-ltermcap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
