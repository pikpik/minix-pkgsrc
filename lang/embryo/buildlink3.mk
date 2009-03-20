# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/26 07:54:20 minskim Exp $

BUILDLINK_TREE+=	embryo

.if !defined(EMBRYO_BUILDLINK3_MK)
EMBRYO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.embryo+=	embryo>=0.9.5.050
BUILDLINK_PKGSRCDIR.embryo?=	../../lang/embryo
.endif # EMBRYO_BUILDLINK3_MK

BUILDLINK_TREE+=	-embryo
