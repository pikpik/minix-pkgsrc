# $NetBSD: Makefile,v 1.5 2004/07/22 09:16:00 recht Exp $

DISTNAME=	JapaneseCodecs-1.4.11
PKGNAME=	${PYPKGPREFIX}-jpCodecs-1.4.11
CATEGORIES=	converters python
MASTER_SITES=	http://www.python.jp/Zope/download/JapaneseCodecs/ \
		http://www.asahi-net.or.jp/~rd6t-kjym/python/JapaneseCodecs/dist/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.asahi-net.or.jp/~rd6t-kjym/python/
COMMENT=	Python Unicode codecs for Japanese charsets

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
