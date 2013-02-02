$NetBSD$

--- Net/testsuite/src/DNSTest.cpp.orig	2012-11-14 12:24:53.000000000 +0000
+++ Net/testsuite/src/DNSTest.cpp
@@ -72,7 +72,7 @@ void DNSTest::testHostByName()
 	
 	try
 	{
-		HostEntry he1 = DNS::hostByName("nohost.appinf.com");
+		HostEntry he2 = DNS::hostByName("nohost.appinf.com");
 		fail("host not found - must throw");
 	}
 	catch (HostNotFoundException&)
