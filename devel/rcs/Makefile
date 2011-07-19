# $NetBSD: Makefile,v 1.27 2008/02/15 15:48:46 gdt Exp $
#

DISTNAME=		rcs-5.7
PKGREVISION=		3
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.purdue.edu/homes/trinkle/RCS/
COMMENT=		GNU Revision Control System - version control software

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "AIX" || ${OPSYS} == "Minix"
DEPENDS+=		diffutils>=2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils
# the native diff/diff3 is not sufficient for rcs
TOOLS_PLATFORM.diff=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}diff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PATH=${LOCALBASE}/bin:"$$PATH"
CONFIGURE_HAS_MANDIR=	no

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/rcslog
	${LN} -s ${DESTDIR}${PREFIX}/bin/rlog ${DESTDIR}${PREFIX}/bin/rcslog
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1.gz
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rlog.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
