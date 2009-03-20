# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:00 jlam Exp $

BUILDLINK_TREE+=	rpm

.if !defined(RPM_BUILDLINK3_MK)
RPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rpm+=	rpm>=2.5.4nb4
BUILDLINK_ABI_DEPENDS.rpm?=	rpm>=2.5.4nb5
BUILDLINK_PKGSRCDIR.rpm?=	../../misc/rpm
BUILDLINK_DEPMETHOD.rpm?=	build

BUILDLINK_CPPFLAGS.rpm= -I${BUILDLINK_PREFIX.rpm}/include/rpm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # RPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-rpm
