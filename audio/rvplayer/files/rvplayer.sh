#!/bin/sh
#
# $NetBSD$
#
REAL_HOME=@@REAL_HOME@@ ; export REAL_HOME
LD_LIBRARY_PATH=${REAL_HOME}:${LD_LIBRARY_PATH} ; export LD_LIBRARY_PATH
exec ${REAL_HOME}/rvplayer "$@"
