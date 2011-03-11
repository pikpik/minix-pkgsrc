# $NetBSD$

BUILDLINK_DEPMETHOD.scintilla?=	build

BUILDLINK_TREE+=	scintilla

.if !defined(SCINTILLA_BUILDLINK3_MK)
SCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scintilla+=	scintilla>=2.23
BUILDLINK_PKGSRCDIR.scintilla?=	../../devel/scintilla

#.include "../../x11/gtk2/buildlink3.mk"
.endif	# SCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-scintilla
