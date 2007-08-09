# $NetBSD$
#
# Common logic to handle Python Eggs
#
.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
# Only Python 2.4 support by devel/py-setuptools right now
PYTHON_VERSIONS_ACCEPTED?=	24

PLIST_SUBST+=	EGG_NAME=${EGGNAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=	EGG_INFODIR=${EGGNAME}-py${PYVERSSUFFIX}.egg-info

_PYSETUPTOOLSINSTALLARGS=	--single-version-externally-managed

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c6:../../devel/py-setuptools

INSTALLATION_DIRS+=	${PYSITELIB}

.include "../../lang/python/extension.mk"
