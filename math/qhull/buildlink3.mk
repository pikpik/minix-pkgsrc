# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/09/19 18:00:54 drochner Exp $

BUILDLINK_TREE+=	qhull

.if !defined(QHULL_BUILDLINK3_MK)
QHULL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qhull+=	qhull>=2003.1
BUILDLINK_PKGSRCDIR.qhull?=	../../math/qhull
.endif # QHULL_BUILDLINK3_MK

BUILDLINK_TREE+=	-qhull
