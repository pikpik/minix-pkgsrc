# $NetBSD$
#

DISTNAME=	IPC-ShareLite-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Light-weight interface to shared memory

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IPC/ShareLite/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL </dev/null

.include "../../mk/bsd.pkg.mk"
