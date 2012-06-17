# $NetBSD$

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.4.2<5.5
BUILDLINK_ABI_DEPENDS.php+=	php>=5.4.2<5.5
BUILDLINK_PKGSRCDIR.php?=	../../lang/php54

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
