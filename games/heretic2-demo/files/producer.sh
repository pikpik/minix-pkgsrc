#!/bin/sh -e
# $NetBSD: wrapper.sh,v 1.2 2002/03/12 15:01:34 abs Exp $
# Simple wrapper for real producer

ulimit -n 256
exec @@PREFIX@@/lib/real/producer/producer "$@"
