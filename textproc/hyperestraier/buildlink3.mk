# $NetBSD$

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HYPERESTRAIER_BUILDLINK3_MK:=	${HYPERESTRAIER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hyperestraier
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhyperestraier}
BUILDLINK_PACKAGES+=	hyperestraier
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hyperestraier

.if ${HYPERESTRAIER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.hyperestraier+=	hyperestraier>=1.1.2
BUILDLINK_PKGSRCDIR.hyperestraier?=	../../textproc/hyperestraier
.endif	# HYPERESTRAIER_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/qdbm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
