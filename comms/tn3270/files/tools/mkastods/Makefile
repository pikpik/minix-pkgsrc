#	$NetBSD: Makefile,v 1.1.1.1 2010/01/17 01:33:25 dholland Exp $

TOP=../..
include $(TOP)/mk/setup.mk

PROG=mkastods
SRCS=mkastods.c ../../api/asc_ebc.c ../../api/ebc_disp.c

CFLAGS+=-I../../api
CFLAGS+=-DHOST_TOOL

# should be hostprog.mk for crosscompiling (FUTURE)
include $(TOP)/mk/prog.mk
