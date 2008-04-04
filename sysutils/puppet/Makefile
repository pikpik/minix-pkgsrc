# $NetBSD: Makefile,v 1.2 2008/03/13 20:05:09 tonnerre Exp $

DISTNAME=		puppet-0.24.4
CATEGORIES=		sysutils

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.reductivelabs.com/projects/puppet/
COMMENT=		Configuration management framework written in Ruby

DEPENDS+=		${RUBY_PKGPREFIX}-facter>=1.3.8:../../sysutils/ruby-facter

GEM_BUILD=		gemspec

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	lib/puppet/reference/configuration.rb
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"

EXAMPLEDIR=		${PREFIX}/share/examples/${PKGBASE}

pre-build:
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppetmasterd			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppetmasterd.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/puppetmasterd.conf		\
		${DESTDIR}${EXAMPLEDIR}

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
