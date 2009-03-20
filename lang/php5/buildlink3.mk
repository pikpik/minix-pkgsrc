# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=		php>=5.1.2
BUILDLINK_ABI_DEPENDS.php+=	php>=5.1.2
BUILDLINK_PKGSRCDIR.php?=	../../lang/php5

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
