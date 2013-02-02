# $NetBSD: hacks.mk,v 1.1 2011/08/19 14:39:09 tnn Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/thunderbird

.include "../../devel/xulrunner/hacks.mk"
