#!/bin/sh
# $NetBSD: snmpd.sh,v 1.1 2000/10/13 18:16:00 kim Exp $

# PID file:
PF=/var/run/snmpd.pid


if [ -f /etc/snmp/snmpd.conf ]
then
    SNMPD_CFG="-c /etc/snmp/snmpd.conf"
fi

case $1 in
start)
	if [ -x @PREFIX@/sbin/snmpd ]
	then
	    echo -n ' snmpd'
	    @PREFIX@/sbin/snmpd -s -P ${PF} -A -l /dev/null ${SNMPD_CFG}
	fi
	;;
stop)
	if [ -f ${PF} ]; then
		kill `cat ${PF}`
		rm -f ${PF}
	fi
	;;
restart)
	sh $0 stop
	sh $0 start
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac

