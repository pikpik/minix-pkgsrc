# $NetBSD: builtin.mk,v 1.1 2008/10/12 20:49:19 ahoka Exp $

BUILTIN_PKG:=	sqlite3

PKGCONFIG_FILE.sqlite3=	/usr/lib/pkgconfig/sqlite3.pc
PKGCONFIG_BASE.sqlite3=	/usr

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
