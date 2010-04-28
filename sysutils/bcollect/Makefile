# $NetBSD: Makefile,v 1.7 2010/01/27 18:24:33 joerg Exp $

DISTNAME=	bcollect-0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.ancient-solutions.com/pub/bsdprojects/bcollect/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://bcollect.ancient-solutions.com/
COMMENT=	Incremental remote backup tool

PKG_DESTDIR_SUPPORT=	destdir
GNU_CONFIGURE=	yes
USE_TOOLS+=	lex yacc

CONF_FILES+=	${PREFIX}/share/examples/bcollect/bcollect.conf	\
		${PKG_SYSCONFDIR}/bcollect.conf

DEPENDS+=	rsync>=3.0.0:../../net/rsync

.include "../../devel/clib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
