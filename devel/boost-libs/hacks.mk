# $NetBSD$

# GCC 3.3.3 enters an infinite loop under NetBSD/amd64 in Boost.Wave's
# insantiate_cpp_literalgrs.cpp source file.  Avoid compiling it.
# To make things simple, apply the hack to all the platforms so that the
# builds are consistent.
BJAM_BUILD+=	<define>BOOST_WAVE_SEPARATE_GRAMMAR_INSTANTIATION=0
