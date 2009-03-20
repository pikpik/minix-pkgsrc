# $NetBSD: buildlink3.mk,v 1.2 2008/10/11 09:31:55 uebayasi Exp $

.include "../../editors/emacs/modules.mk"

BUILDLINK_TREE+=	mell

.if !defined(MELL_BUILDLINK3_MK)
MELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mell+=	${EMACS_PKGNAME_PREFIX}mell>=1.0.0
BUILDLINK_PKGSRCDIR.mell?=	../../devel/mell

BUILDLINK_CONTENTS_FILTER.mell= ${EGREP} '.*\.el$$|.*\.elc$$'
.endif # MELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mell
