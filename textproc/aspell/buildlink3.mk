# $NetBSD: buildlink3.mk,v 1.14 2007/01/06 22:07:42 wiz Exp $

BUILDLINK_TREE+=	aspell

.if !defined(ASPELL_BUILDLINK3_MK)
ASPELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aspell+=	aspell>=0.50.3
BUILDLINK_ABI_DEPENDS.aspell+=	aspell>=0.60.4nb1
BUILDLINK_PKGSRCDIR.aspell?=	../../textproc/aspell

BUILDLINK_FILES.aspell=	bin/aspell bin/prezip-bin bin/word-list-compress
.endif # ASPELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-aspell
