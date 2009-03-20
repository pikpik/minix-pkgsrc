# $NetBSD: buildlink3.mk,v 1.4 2009/01/11 03:11:37 smb Exp $

BUILDLINK_TREE+=	claws-mail

.if !defined(CLAWS_MAIL_BUILDLINK3_MK)
CLAWS_MAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.claws-mail+= claws-mail>=3.7.0
BUILDLINK_PKGSRCDIR.claws-mail?=	../../mail/claws-mail
.endif # CLAWS_MAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-claws-mail
