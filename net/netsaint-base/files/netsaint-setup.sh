#!/bin/sh
#
#	$NetBSD$
#
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/log/netsaint/archives
install -m 0755 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/run/netsaint/rw
