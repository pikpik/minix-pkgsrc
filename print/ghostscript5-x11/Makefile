# $NetBSD: Makefile,v 1.5 2000/04/16 17:44:28 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-x11-/}nb2
CATEGORIES+=	x11

CONFLICTS=	ghostscript-*

USE_X11=	# defined

MAKE_ENV+=	USE_X11=
SCRIPTS_ENV+=	USE_X11=yes

.include "../../print/ghostscript5/Makefile.common"
