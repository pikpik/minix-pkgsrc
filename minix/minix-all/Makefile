# $NetBSD$

DISTNAME=		minix-all-20110728
CATEGORIES=		minix meta-pkgs
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tcort@minix3.org
HOMEPAGE=		http://minix3.org/
COMMENT=		meta package used to install all packages

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		pkgin-[0-9]*:../../pkgtools/pkgin

.include "../../mk/bsd.prefs.mk"

do-extract:
	${MKDIR} -p ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

print-PLIST:
	@${ECHO} "@comment \$$NetBSD\$$";
	@${ECHO} "@exec pkgin up";
	@for package in $$(cat ../limited_list.pbulk | grep -v minix-all); \
	do \
		${ECHO} "@exec pkgin -y in $$(cd ../../$${package} && bmake show-var VARNAME=PKGNAME)"; \
	done

.include "../../mk/bsd.pkg.mk"
