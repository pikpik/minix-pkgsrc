#!/bin/sh

# $NetBSD$

CINTSYSDIR=XXXPREFIXXXX/cint
export CINTSYSDIR
exec XXXPREFIXXXX/cint/`basename $0` $*
