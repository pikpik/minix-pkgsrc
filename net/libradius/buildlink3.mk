# $NetBSD: buildlink3.mk,v 1.9 2006/12/12 21:52:37 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBRADIUS_BUILDLINK3_MK:=	${LIBRADIUS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libradius
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibradius}
BUILDLINK_PACKAGES+=	libradius
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libradius

.if ${LIBRADIUS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libradius+=	libradius>=20040827
BUILDLINK_PKGSRCDIR.libradius?=	../../net/libradius
BUILDLINK_DEPMETHOD.libradius?=	build

.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "FreeBSD"
BUILDLINK_LDADD.libradius+=	-lmd
BUILDLINK_LDFLAGS.libradius?=	${BUILDLINK_LDADD.libradius}
.  endif
.endif	# LIBRADIUS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
