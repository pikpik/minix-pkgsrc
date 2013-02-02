# $NetBSD$

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=3.5.1
BUILDLINK_PKGSRCDIR.ocamlnet?=	../../net/ocamlnet

.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
