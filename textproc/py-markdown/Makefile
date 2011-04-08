# $NetBSD: Makefile,v 1.1.1.1 2006/10/31 22:39:18 joerg Exp $

DISTNAME=	Markdown-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-markdown/} \
		http://pypi.python.org/packages/source/M/Markdown/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freewisdom.org/projects/python-markdown/
COMMENT=	XHTML generator using a simple markup
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
