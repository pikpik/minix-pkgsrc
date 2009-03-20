# $NetBSD: buildlink3.mk,v 1.2 2008/06/22 03:31:52 taca Exp $

BUILDLINK_TREE+=	${RUBY_PKGPREFIX}-rcairo

.if !defined(RUBY_RCAIRO_BUILDLINK3_MK)
RUBY_RCAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby18-rcairo+=	${RUBY_PKGPREFIX}-rcairo>=1.6.0
BUILDLINK_PKGSRCDIR.ruby18-rcairo?=	../../graphics/ruby-rcairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # RUBY_RCAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-${RUBY_PKGPREFIX}-rcairo
