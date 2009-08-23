# $NetBSD$

BUILDLINK_TREE+=	libprelude-ruby

.if !defined(LIBPRELUDE_RUBY_BUILDLINK3_MK)
LIBPRELUDE_RUBY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-ruby+=	libprelude-ruby>=0.9.24
BUILDLINK_PKGSRCDIR.libprelude-ruby?=	../../security/libprelude-ruby
.endif	# LIBPRELUDE_RUBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-ruby
