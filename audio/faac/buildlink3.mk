# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_TREE+=	faac

.if !defined(FAAC_BUILDLINK3_MK)
FAAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faac+=	faac>=1.24
BUILDLINK_ABI_DEPENDS.faac+=	faac>=1.24nb1
BUILDLINK_PKGSRCDIR.faac?=	../../audio/faac
.endif # FAAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-faac
