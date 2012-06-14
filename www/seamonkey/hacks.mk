# $NetBSD: hacks.mk,v 1.3 2012/03/19 10:35:57 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/seamonkey

.include "../../devel/xulrunner/hacks.mk"
