# $NetBSD: Makefile,v 1.20 2001/10/24 22:10:50 jlam Exp $
#

DISTNAME=		gtksql-0.3
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/
COMMENT=		Query tool for PostgreSQL written with GTK

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
MAKE_ENV+=		MCFLAGS="${CFLAGS}"

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
