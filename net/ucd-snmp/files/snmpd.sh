#!/bin/sh
# $NetBSD$

if [ -f /etc/snmp/snmpd.conf ]
then
    SNMPD_CFG="-c /etc/snmp/snmpd.conf"
fi

if [ -x @PREFIX@/sbin/snmpd ]
then
    echo -n ' snmpd'
    @PREFIX@/sbin/snmpd -s -P /var/run/snmpd.pid -A -l /dev/null ${SNMPD_CFG}
fi
