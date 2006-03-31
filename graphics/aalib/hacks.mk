# $NetBSD$

### [Mon Mar 25 14:45:05 2002 UTC : cjep]
### On arm{,32}, avoid internal compiler errors with old GCC versions.
###
.if (${MACHINE_ARCH} == "arm") || (${MACHINE_ARCH} == "arm32")
GCC_REQD+=	2.95.3
.endif
