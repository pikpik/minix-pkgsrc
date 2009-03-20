# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/29 13:11:14 obache Exp $

BUILDLINK_TREE+=	sigscheme

.if !defined(SIGSCHEME_BUILDLINK3_MK)
SIGSCHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sigscheme+=	sigscheme>=0.8.0
BUILDLINK_PKGSRCDIR.sigscheme?=	../../lang/sigscheme

.include "../../devel/libgcroots/buildlink3.mk"
.endif # SIGSCHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-sigscheme
