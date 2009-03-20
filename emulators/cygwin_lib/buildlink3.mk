# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_TREE+=	cygwin_lib

.if !defined(CYGWIN_LIB_BUILDLINK3_MK)
CYGWIN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cygwin_lib+=		cygwin_lib>=1.5.11.1
BUILDLINK_PKGSRCDIR.cygwin_lib?=	../../emulators/cygwin_lib
.endif # CYGWIN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cygwin_lib
