# $NetBSD: builtin.mk,v 1.6 2006/04/18 19:48:30 reed Exp $

BUILTIN_PKG:=	x11

BUILTIN_FIND_FILES_VAR:=	CF_XORG
BUILTIN_FIND_FILES.CF_XORG=	${X11BASE}/lib/X11/config/xorg.cf

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.x11)
IS_BUILTIN.x11=	no
.  if empty(CF_XORG:M__nonexistent__) && empty(CF_XORG:M${LOCALBASE}/*)
IS_BUILTIN.x11=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.x11

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.x11) && \
    !empty(IS_BUILTIN.x11:M[yY][eE][sS]) && \
    empty(CF_XORG:M__nonexistent__)
.  include "${BUILDLINK_PKGSRCDIR.x11}/version.mk"
BUILTIN_PKG.x11=	xorg-libs-${BUILTIN_X11_VERSION.xorg}
.endif
MAKEVARS+=	BUILTIN_PKG.x11

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.x11)
.  if ${PREFER.x11} == "pkgsrc"
USE_BUILTIN.x11=	no
.  else
USE_BUILTIN.x11=	${IS_BUILTIN.x11}
.    if defined(BUILTIN_PKG.x11) && \
        !empty(IS_BUILTIN.x11:M[yY][eE][sS])
USE_BUILTIN.x11=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.x11}
.        if !empty(USE_BUILTIN.x11:M[yY][eE][sS])
USE_BUILTIN.x11!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.x11:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.x11
.endif
MAKEVARS+=	USE_BUILTIN.x11

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.x11?=	no
.if !empty(CHECK_BUILTIN.x11:M[nN][oO])

.  if !empty(USE_BUILTIN.x11:M[yY][eE][sS])
BUILDLINK_PREFIX.x11=	${X11BASE}
BUILDLINK_FILES.x11+=	lib/pkgconfig/xorg-libs.pc
.  endif

.endif	# CHECK_BUILTIN.x11


