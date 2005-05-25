# $NetBSD: Makefile,v 1.2 2004/11/07 21:46:57 jmmv Exp $
#

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}

CONFLICTS+=		wistumbler2-[0-9]*

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
