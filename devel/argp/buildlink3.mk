# $NetBSD$
# Packages that only install static libraries or headers should
# include the following line:
#
# BUILDLINK_DEPMETHOD.argp?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ARGP_BUILDLINK3_MK:=	${ARGP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	argp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nargp}
BUILDLINK_PACKAGES+=	argp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}argp

.if ${ARGP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.argp+=	argp>=1.3
BUILDLINK_PKGSRCDIR.argp?=	../../devel/argp
.endif	# ARGP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
