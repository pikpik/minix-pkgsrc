#!/bin/sh
#
# $NetBSD$
#

case "$1" in
	start)
		if [ -r /etc/isakmpd/isakmpd.conf ]; then
			echo 'Starting isakmpd'
			@PREFIX@/sbin/isakmpd
		fi
		;;
	stop)
		if [ -f /var/run/isakmpd.pid ]; then
			echo 'Stopping isakmpd'
			kill `cat /var/run/isakmpd.pid`
			rm -f /var/run/isakmpd.pid
		fi
		;;
	*)
		echo "$0 start | stop"
		;;
esac
