#!/bin/sh
#
# $NetBSD$
#
# Wrapper to execute maildirmake from amongst any installed maildirmake
# executable.

maildirmakes=" \
	@LOCALBASE@/bin/imapd.maildirmake \
	@LOCALBASE@/bin/maildrop.maildirmake \
	"

maildirmake=NONE
for file in ${maildirmakes}
do
	if [ -x ${file} ]
	then
		maildirmake=${file}
	fi
done

if [ "${maildirmake}" = "NONE" ]
then
	@ECHO@ "$0: can't find a valid maildirmake executable"
	exit 1
fi

exec ${maildirmake} $*
