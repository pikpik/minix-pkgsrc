# $NetBSD$

BUILDLINK_TREE+=	ocamlnet

.if !defined(OCAMLNET_BUILDLINK3_MK)
OCAMLNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlnet+=	ocamlnet>=1.1.2nb1
BUILDLINK_PKGSRCDIR.ocamlnet?=	../../net/ocamlnet

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAMLNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlnet
