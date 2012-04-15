# $NetBSD: options.mk,v 1.2 2011/02/25 20:37:56 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencv
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	python
.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
PLIST.python=	yes
.else
CMAKE_ARGS+=	-D BUILD_NEW_PYTHON_SUPPORT=OFF
.endif

# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=    -D WITH_OPENEXR:BOOL=OFF
CMAKE_ARGS+=	-D BUILD_DOXYGEN_DOCS=OFF
