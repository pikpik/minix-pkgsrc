# $NetBSD: buildlink3.mk,v 1.4 2010/01/17 12:02:42 wiz Exp $

BUILDLINK_TREE+=	ocaml-cryptokit

.if !defined(OCAML_CRYPTOKIT_BUILDLINK3_MK)
OCAML_CRYPTOKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cryptokit+=	ocaml-cryptokit>=1.5
BUILDLINK_ABI_DEPENDS.ocaml-cryptokit?=	ocaml-cryptokit>=1.5
BUILDLINK_PKGSRCDIR.ocaml-cryptokit?=	../../security/ocaml-cryptokit

.include "../../lang/ocaml/buildlink3.mk"
.endif # OCAML_CRYPTOKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cryptokit
