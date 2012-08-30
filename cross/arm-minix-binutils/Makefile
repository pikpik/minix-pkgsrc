# $NetBSD: Makefile,v 1.16 2010/06/20 16:23:56 tron Exp $

.include "../../devel/binutils/Makefile.common"

PKGNAME=		arm-minix-binutils-2.22
PKGREVISION=		1
CATEGORIES=		cross

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		GNU binutils for MINIX on ARM

USE_TOOLS+=		find makeinfo sort

CONFIGURE_ARGS+=	--target=arm-minix-elf --program-prefix=arm-minix-elf- 
# Do not generate Info files, as they will conflict with the native ones anyway
INFO_FILES=     no

.include "../../mk/bsd.pkg.mk"
