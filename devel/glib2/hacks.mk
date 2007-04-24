# $NetBSD$

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	defined

# Build without optimization. Avoids crash in libgobject on gtk2 initialization.
# Bug is triggered regardless of whether we're using gcc or aCC.
.if !empty(MACHINE_PLATFORM:MHPUX-*-hppa)
PKG_HACKS+=	hppa-codegen
CFLAGS:=	-O0 ${CFLAGS:C/[+,-]O[0-9]?//g}
.endif

.endif		# GLIB2_HACKS_MK
