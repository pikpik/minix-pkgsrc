#!/bin/sh
#	$NetBSD$

if [ -f @PREFIX@/libexec/skkserv ]; then
	echo -n ' skkserv'
	PATH=@PREFIX@/libexec skkserv
fi
