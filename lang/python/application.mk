# $NetBSD: application.mk,v 1.5 2004/01/14 03:22:47 xtraeme Exp $

.include "../../lang/python/pyversion.mk"

# replace shell magic by python version specific path
# PYTHON_PATCH_SCRIPTS is a list of Python scripts to be installed,
#  relative to ${WRKSRC}

.if defined(PYTHON_PATCH_SCRIPTS)
REPLACE_INTERPRETER+=	python
_REPLACE.python.old=	.*python[^ ]*
_REPLACE.python.new=	${PYTHONBIN}
_REPLACE_FILES.python=	${PYTHON_PATCH_SCRIPTS}
.endif
