# $NetBSD$

BUILDLINK_TREE+=	mecab-base

.if !defined(MECAB_BASE_BUILDLINK3_MK)
MECAB_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mecab-base+=	mecab-base>=0.90<0.99
BUILDLINK_PKGSRCDIR.mecab-base?=	../../textproc/mecab-base09
BUILDLINK_FILES.mecab-base+=		include/mecab.h
BUILDLINK_FILES.mecab-base+=		lib/libmecab.*

.include "../../mk/pthread.buildlink3.mk"
.endif # MECAB_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mecab-base
