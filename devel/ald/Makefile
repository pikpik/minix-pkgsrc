# $NetBSD: Makefile,v 1.11 2006/09/09 02:41:56 obache Exp $
#

DISTNAME=	ald-0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ald/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ald.sourceforge.net/
COMMENT=	Very nice x86 assembly-level debugger

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=	YES

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
