# $NetBSD: application.mk,v 1.8 2007/01/24 09:59:02 rillig Exp $
#
# Replace the #! interpreter for Python scripts.
#
# Package-settable variables:
#
# REPLACE_PYTHON
#	A list of Python scripts to be installed, relative to ${WRKSRC}.
#
# PYTHON_PATCH_SCRIPTS
#	The same as REPLACE_PYTHON.
#
# Keywords: python
#

.include "../../lang/python/pyversion.mk"

.if defined(PYTHON_PATCH_SCRIPTS) || defined(REPLACE_PYTHON)
REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*python[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${PYTHON_PATCH_SCRIPTS} ${REPLACE_PYTHON}
.endif
