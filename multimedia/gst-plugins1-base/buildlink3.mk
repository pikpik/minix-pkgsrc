# $NetBSD: buildlink3.mk,v 1.16 2012/09/15 10:05:47 obache Exp $

BUILDLINK_TREE+=	gst-plugins1-base

.if !defined(GST_PLUGINS1_BASE_BUILDLINK3_MK)
GST_PLUGINS1_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.0.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.0.0
BUILDLINK_PKGSRCDIR.gst-plugins1-base?=		../../multimedia/gst-plugins1-base

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.endif # GST_PLUGINS1_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-base
