# $NetBSD: buildlink3.mk,v 1.9 2006/08/08 15:19:15 wiz Exp $

BUILDLINK_TREE+=	ladspa

.if !defined(LADSPA_BUILDLINK3_MK)
LADSPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ladspa+=	ladspa>=1.12
BUILDLINK_ABI_DEPENDS.ladspa?=	ladspa>=1.12nb1
BUILDLINK_PKGSRCDIR.ladspa?=	../../audio/ladspa
.endif # LADSPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ladspa
