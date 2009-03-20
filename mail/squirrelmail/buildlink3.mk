# $NetBSD: buildlink3.mk,v 1.20 2008/12/04 07:18:46 martti Exp $

BUILDLINK_TREE+=	squirrelmail

.if !defined(SQUIRRELMAIL_BUILDLINK3_MK)
SQUIRRELMAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.squirrelmail+=	squirrelmail>=1.4.17
BUILDLINK_PKGSRCDIR.squirrelmail?=	../../mail/squirrelmail
.endif # SQUIRRELMAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-squirrelmail
