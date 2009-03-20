# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_TREE+=	librep

.if !defined(LIBREP_BUILDLINK3_MK)
LIBREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librep+=	librep>=0.17
BUILDLINK_ABI_DEPENDS.librep+=	librep>=0.17nb2
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep
MAKE_FLAGS+=			rep_LIBTOOL=${LIBTOOL:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # LIBREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librep
