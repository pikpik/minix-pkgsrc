# $NetBSD: Makefile,v 1.5 2001/02/17 18:24:48 wiz Exp $
#

DISTNAME=	grepmail-4.80
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	mbox formatted file search utility

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/grepmail/.packlist

MAKE_PARAMS+=	INSTALLDIRS=site
MAKE_PARAMS+=	FASTREADER=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
