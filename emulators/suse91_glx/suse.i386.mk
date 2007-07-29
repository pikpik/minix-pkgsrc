# $NetBSD: Makefile.i386,v 1.1 2006/01/08 16:53:21 salo Exp $

# SuSE i386 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	XFree86-Mesa-4.3.99.902-40.${SUSE_ARCH}.rpm
DISTFILES+=	XFree86-Mesa-devel-4.3.99.902-40.${SUSE_ARCH}.rpm
