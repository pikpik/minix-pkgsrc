# $NetBSD: buildlink3.mk,v 1.9 2008/01/18 05:08:20 tnn Exp $

BUILDLINK_TREE+=	Pantomime

.if !defined(PANTOMIME_BUILDLINK3_MK)
PANTOMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Pantomime+=	Pantomime>=1.1.2
BUILDLINK_ABI_DEPENDS.Pantomime+=	Pantomime>=1.1.2nb5
BUILDLINK_PKGSRCDIR.Pantomime?=	../../mail/Pantomime

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Pantomime+=	${GNUSTEP_LOCAL_ROOT:Q}/${GNUSTEP_IDIR:Q}/Pantomime

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # PANTOMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-Pantomime
