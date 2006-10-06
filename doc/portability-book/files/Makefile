# $NetBSD: Makefile,v 1.12 2006/09/19 17:50:38 rillig Exp $

DOC=	portability

SRCS=	portability.xml
SRCS+=	chapters.ent
SRCS+=	intro.xml
SRCS+=	utilities.xml
SRCS+=	headers.xml
SRCS+=	functions.xml
SRCS+=	devices.xml

# Make deeper TOC:
XSL_DBX_WITH_TOC_SECTION_DEPTH?= 2 

# Avoid extra normalization
NO_TIDY?=	yes


all:	# doing this as depends doesn't work
	${MAKE} html-split
	${MAKE} html
	${MAKE} ascii
	${MAKE} pdf

WEB_PREFIX=	${.CURDIR}/../htdocs
.include "../htdocs/share/mk/doc.docbook.mk"
