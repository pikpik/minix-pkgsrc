# $NetBSD$
#

_MAGIC_H=	/usr/include/magic.h

.if !defined(IS_BUILTIN.file)
IS_BUILTIN.file=	no
.  if exists(${_MAGIC_H})
IS_BUILTIN.file!=							\
	if ${GREP} -q "magic_file" ${_MAGIC_H}; then			\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.file
.endif	# IS_BUILTIN.file

.if !defined(USE_BUILTIN.file)
USE_BUILTIN.file?=	${IS_BUILTIN.file}
PREFER.file?=		pkgsrc
.endif	# USE_BUILTIN.file
