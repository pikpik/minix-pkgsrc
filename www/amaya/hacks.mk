# $NetBSD$

.include "../../mk/bsd.prefs.mk"

# Workaround for PR 45266
.if ${OPSYS} == "NetBSD"
BUILDLINK_INCDIRS.heimdal=	# empty
.endif

