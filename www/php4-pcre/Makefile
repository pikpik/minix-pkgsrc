# $NetBSD: Makefile,v 1.4 2001/05/14 14:12:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pcre
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for Perl-compatible regular expressions

DEPENDS+=		pcre>=3.4:../../devel/pcre

EVAL_PREFIX+=		PCREDIR=pcre
CONFIGURE_ARGS+=	--with-pcre-regex=shared,${PCREDIR}

.include "../../mk/bsd.pkg.mk"
