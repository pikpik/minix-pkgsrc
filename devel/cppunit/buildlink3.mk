# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_TREE+=	cppunit

.if !defined(CPPUNIT_BUILDLINK3_MK)
CPPUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
BUILDLINK_ABI_DEPENDS.cppunit?=	cppunit>=1.10.2nb5
BUILDLINK_PKGSRCDIR.cppunit?=	../../devel/cppunit
BUILDLINK_CPPFLAGS.cppunit+=	-I${BUILDLINK_PREFIX.cppunit}/include/cppunit
.endif # CPPUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppunit
