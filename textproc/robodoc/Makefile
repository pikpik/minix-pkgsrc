# $NetBSD: Makefile,v 1.8 2005/12/05 20:51:08 rillig Exp $
#

DISTNAME=	robodoc-3.2.3
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=robodoc/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/robodoc/
COMMENT=	Tool to support project documentation within source code

GNU_CONFIGURE=	YES
USE_TOOLS+=	gm4 gmake

SUBST_CLASSES+=		gm4
SUBST_FILES.gm4=	Docs/makefile.in
SUBST_SED.gm4+=		-e 's,@M4@,${TOOLS_M4},g'
SUBST_STAGE.gm4=	post-patch

MAKEFILE=	makefile

.include "../../mk/bsd.pkg.mk"
