# $NetBSD: Makefile,v 1.3 2001/11/26 06:49:36 jlam Exp $

DISTNAME=		Archive-Tar-0.22
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to manipulate tar files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
