# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP extension for MS SQL databases

USE_BUILDLINK3=		yes

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}/freetds

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
