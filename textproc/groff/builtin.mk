# $NetBSD: builtin.mk,v 1.2 2004/07/09 12:30:17 drochner Exp $

.if !defined(IS_BUILTIN.groff)
.  if exists(/usr/bin/groff)
IS_BUILTIN.groff=	yes
.  else
IS_BUILTIN.groff=	no
.  endif
.endif  # IS_BUILTIN.groff

USE_BUILTIN.groff?=	${IS_BUILTIN.groff}
GROFF?=			${BUILDLINK_PREFIX.groff}/bin/groff
TBL?=			${BUILDLINK_PREFIX.groff}/bin/tbl
