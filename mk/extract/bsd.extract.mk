# $NetBSD: bsd.pkg.extract.mk,v 1.24 2006/06/04 04:31:47 jlam Exp $
#
# This Makefile fragment is included to bsd.pkg.mk and defines the
# relevant variables and targets for the "extract" phase.
#
# The following are the "public" targets provided by this module:
#
#    extract
#
# The following targets may be overridden in a package Makefile:
#
#    pre-extract, do-extract, post-extract
#

.include "${PKGSRCDIR}/mk/extract/extract.mk"
