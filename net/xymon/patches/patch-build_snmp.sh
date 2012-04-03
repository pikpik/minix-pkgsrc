$NetBSD$

make it possible to deal with a net-snmp-config that's not in the default path

--- build/snmp.sh.orig	2008-09-30 16:37:31.000000000 +0000
+++ build/snmp.sh
@@ -2,8 +2,15 @@
 
 	SNMPINC=""
 	SNMPLIB=""
+	SNMPCONFIG=""
+
+	if test "$USERSNMPCONFIG" != ""; then
+		SNMPCONFIG="$USERSNMPCONFIG"
+	else
+		SNMPCONFIG="net-snmp-config" # it might be in the path
+	fi
+	VERSION=`${SNMPCONFIG} --version`    
 
-	VERSION=`net-snmp-config --version`
 	if test $? -eq 0
 	then
 		echo "Found Net-SNMP version $VERSION"
