# $NetBSD: module.mk,v 1.7 2006/06/02 18:27:55 joerg Exp $

# This file is now only needed to patch up PKGNAME until PHP 5.2.10 or later is
# released. 
.if "${PHP_BASE_VERS}" == "5.2.9"
PKGNAME=		${PHP_PKG_PREFIX}-${MODNAME}-${PHP_BASE_VERS}.99
.endif
