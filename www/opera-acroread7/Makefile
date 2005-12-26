# $NetBSD: Makefile,v 1.2 2005/09/28 12:33:28 rillig Exp $

DISTNAME= 		opera-acroread7-1.0

MAINTAINER=		jschauma@NetBSD.org
COMMENT=		Acrobat Reader 7 plugin for opera

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

DEPENDS+=		acroread7-7.[0-9]*:../../print/acroread7
CONFLICTS+=		opera-acroread-[0-9]*
CONFLICTS+=		opera-acroread3-[0-9]*
CONFLICTS+=		opera-acroread5-[0-9]*

ACROREAD=		Acrobat7
ACRO_SUBDIR=		Browser

.include "../../www/opera-acroread/Makefile.common"
