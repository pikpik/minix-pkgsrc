# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:39 jdolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../lang/php/ext.mk"
.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
