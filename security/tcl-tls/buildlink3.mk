# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_TREE+=	tcl-tls

.if !defined(TCL_TLS_BUILDLINK3_MK)
TCL_TLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-tls+=	tcl-tls>=1.5.0
BUILDLINK_PKGSRCDIR.tcl-tls?=	../../security/tcl-tls
.endif # TCL_TLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-tls
