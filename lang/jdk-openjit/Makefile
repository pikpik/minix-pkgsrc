# $NetBSD: Makefile,v 1.2 2003/07/02 10:27:06 jlam Exp $

PKGNAME=	jdk-openjit-${OPENJIT_VERSION}

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

PKG_JVMS_ACCEPTED= jdk
CLASSDIR=	classes
JRELIB=		lib/${MACHINE_ARCH}/green_threads

.include "../../lang/jdk-openjit/Makefile.common"
