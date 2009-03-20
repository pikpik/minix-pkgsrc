# $NetBSD: buildlink3.mk,v 1.4 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	gettext-asprintf

.if !defined(GETTEXT_ASPRINTF_BUILDLINK3_MK)
GETTEXT_ASPRINTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gettext-asprintf+=	gettext-asprintf>=0.14.5
BUILDLINK_PKGSRCDIR.gettext-asprintf?=	../../devel/gettext-asprintf
.endif # GETTEXT_ASPRINTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gettext-asprintf
