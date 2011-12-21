# $NetBSD$

DISTNAME=	topgit_0.7.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/topgit/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://repo.or.cz/w/topgit.git
COMMENT=	Different patch queue manager

USE_TOOLS+=	bash
REPLACE_BASH=	*.sh hooks/*.sh

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Minix"
SUBST_CLASSES+=          sedsyntax
SUBST_FILES.sedsyntax=   tg-export.sh tg-info.sh tg-mail.sh tg-patch.sh tg-summary.sh tg-update.sh 
SUBST_MESSAGE.sedsyntax= Fixing sed syntax
SUBST_SED.sedsyntax=     -e 's,\\(heads\\|top-bases\\),(heads|top-bases),' -e 's/ sed /sed -E /g'
SUBST_STAGE.sedsyntax=   post-patch
.endif

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_ENV+=	prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
