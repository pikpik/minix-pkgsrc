# $NetBSD: buildlink2.mk,v 1.1 2002/10/24 22:24:24 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		psycopg
BUILDLINK_DEPENDS.psycopg?=	${PYPKGPREFIX}-psycopg-*
BUILDLINK_PKGSRCDIR.psycopg?=	../../databases/py-psycopg
