# $NetBSD$

.if !defined(IS_BUILTIN.groff)
IS_BUILTIN.groff=    no
.  if exists(/usr/bin/groff)
IS_BUILTIN.groff=    yes
.  endif
.endif  # IS_BUILTIN.groff

USE_BUILTIN.groff?=  ${IS_BUILTIN.groff}
