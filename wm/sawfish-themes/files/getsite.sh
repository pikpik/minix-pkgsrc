#!/bin/sh
# $NetBSD: $
# generate MASTER_SITE URL for themes from themes.freshmeat.net

THEME=${1%%-[0-9]*.*}
BASEURL="http://download.freshmeat.net/themes"
echo "${BASEURL}/${THEME}/"
