# $NetBSD$

# gcc in MirBSD does not recognize these options
.if ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden rm:-fvisibility-inlines-hidden
.endif
