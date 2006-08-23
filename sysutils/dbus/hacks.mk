# $NetBSD$

# gcc 2.95 does not understand -Wfloat-equal
BUILDLINK_TRANSFORM+=	rm:-Wfloat-equal
