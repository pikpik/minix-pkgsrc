#!/bin/sh

# $NetBSD$

ROOTSYS=XXXPREFIXXXX/root
export ROOTSYS
PATH=XXXPREFIXXXX/root/bin:${PATH}
exec XXXPREFIXXXX/root/bin/`basename $0` $*
