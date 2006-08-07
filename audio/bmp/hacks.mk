# $NetBSD$

.include "../../mk/compiler.mk"

# gcc 4.x generates code that produces background noise during playback.
# Disabling optimizations when using this compiler solves the problem.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=		-O0
CXXFLAGS+=		-O0
.endif
