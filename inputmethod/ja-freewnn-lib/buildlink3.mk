# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:53 jlam Exp $

BUILDLINK_TREE+=	ja-FreeWnn-lib

.if !defined(JA_FREEWNN_LIB_BUILDLINK3_MK)
JA_FREEWNN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ja-FreeWnn-lib+=	ja-FreeWnn-lib>=1.10nb3
BUILDLINK_PKGSRCDIR.ja-FreeWnn-lib?=	../../inputmethod/ja-freewnn-lib
BUILDLINK_DEPMETHOD.ja-freewnn?=	build
.endif # JA_FREEWNN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ja-FreeWnn-lib
