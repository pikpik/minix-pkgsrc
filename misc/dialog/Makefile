# $NetBSD: Makefile,v 1.8 2001/02/17 18:08:58 wiz Exp $
#

DISTNAME=       dialog-0.6z
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_SUNSITE:=utils/shell/}

MAINTAINER=	jlam@netbsd.org
COMMENT=	Display dialog boxes from shell scripts

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
#USE_CURSES=		# undefined

EGDIR=			${PREFIX}/share/examples/dialog
EGFILES=		checklist guage infobox inputbox menubox msgbox
EGFILES+=		radiolist textbox yesno

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/samples; for file in ${EGFILES}; do		\
		${MV} $${file} $${file}.tmp;				\
		${SED} "s|\.\./dialog|${PREFIX}/bin/dialog|g"		\
			$${file}.tmp > $${file};			\
		${RM} $${file}.tmp;					\
		${INSTALL_SCRIPT} $${file} ${EGDIR};			\
	done

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
