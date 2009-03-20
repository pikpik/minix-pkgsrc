# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:56 jlam Exp $

BUILDLINK_TREE+=	tcl-expect

.if !defined(TCL_EXPECT_BUILDLINK3_MK)
TCL_EXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb1
BUILDLINK_ABI_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb2
BUILDLINK_PKGSRCDIR.tcl-expect?=	../../lang/tcl-expect

.include "../../lang/tcl/buildlink3.mk"
.endif # TCL_EXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-expect
