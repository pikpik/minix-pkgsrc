# $NetBSD: Makefile.x86_64,v 1.1 2006/01/08 16:53:21 salo Exp $

# SuSE x86_64 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	XFree86-Mesa-4.3.99.902-30.${SUSE_ARCH}.rpm
DISTFILES+=	XFree86-Mesa-devel-4.3.99.902-30.${SUSE_ARCH}.rpm
