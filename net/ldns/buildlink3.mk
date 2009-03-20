# $NetBSD: buildlink3.mk,v 1.3 2008/12/17 17:52:33 joerg Exp $

BUILDLINK_TREE+=	ldns

.if !defined(LDNS_BUILDLINK3_MK)
LDNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ldns+=	ldns>=1.4
BUILDLINK_PKGSRCDIR.ldns?=	../../net/ldns
.endif # LDNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ldns
