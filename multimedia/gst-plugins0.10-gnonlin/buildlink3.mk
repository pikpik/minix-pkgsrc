# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/02/08 21:42:26 drochner Exp $

BUILDLINK_TREE+=	gst-gnonlin

.if !defined(GST_GNONLIN_BUILDLINK3_MK)
GST_GNONLIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-gnonlin+=	gst-gnonlin>=0.10.6
BUILDLINK_PKGSRCDIR.gst-gnonlin?=	../../multimedia/gst-plugins0.10-gnonlin
.endif # GST_GNONLIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-gnonlin
