# $NetBSD: buildlink3.mk,v 1.9 2007/03/12 06:42:33 wiz Exp $

BUILDLINK_TREE+=	cmake

.if !defined(CMAKE_BUILDLINK3_MK)
CMAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmake+=	cmake>=2.4.6nb3
BUILDLINK_PKGSRCDIR.cmake?=	../../devel/cmake
BUILDLINK_DEPMETHOD.cmake?=	build
BUILDLINK_FILES.cmake+=		share/cmake-*/include/*
.endif # CMAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmake
