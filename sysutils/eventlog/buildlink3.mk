# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:25 joerg Exp $

BUILDLINK_TREE+=	eventlog

.if !defined(EVENTLOG_BUILDLINK3_MK)
EVENTLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eventlog+=	eventlog>=0.2.12
BUILDLINK_PKGSRCDIR.eventlog?=	../../sysutils/eventlog
.endif # EVENTLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-eventlog
