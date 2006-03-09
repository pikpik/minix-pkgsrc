# $NetBSD: Makefile,v 1.14 2005/05/23 09:17:45 rillig Exp $
#

.include "Makefile.common"

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	.*/bin/bash
_REPLACE.bash.new=	${SH:Q}
_REPLACE_FILES.bash=	teach-ce.in

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
