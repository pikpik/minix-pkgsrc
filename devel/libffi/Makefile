# $NetBSD: Makefile,v 1.9 2002/10/04 08:59:34 jlam Exp $

DISTNAME=	gcc-3.3
PKGNAME=	libffi-2.0beta
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	with_target_subdir=.

WRKSRC=		${WRKDIR}/${DISTNAME}/libffi

.include "../../mk/bsd.pkg.mk"
