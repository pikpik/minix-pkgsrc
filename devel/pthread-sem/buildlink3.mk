# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:47 jlam Exp $

BUILDLINK_TREE+=	pthread-sem

.if !defined(PTHREAD_SEM_BUILDLINK3_MK)
PTHREAD_SEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pthread-sem+=		pthread-sem>=1.0
BUILDLINK_PKGSRCDIR.pthread-sem?=	../../devel/pthread-sem
.endif # PTHREAD_SEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-pthread-sem
