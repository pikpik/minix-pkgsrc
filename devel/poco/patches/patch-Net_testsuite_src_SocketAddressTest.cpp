$NetBSD$

--- Net/testsuite/src/SocketAddressTest.cpp.orig	2012-11-14 12:28:07.000000000 +0000
+++ Net/testsuite/src/SocketAddressTest.cpp
@@ -78,7 +78,7 @@ void SocketAddressTest::testSocketAddres
 
 	try
 	{
-		SocketAddress sa3("192.168.1.100", "f00bar");
+		SocketAddress sa3a("192.168.1.100", "f00bar");
 		fail("bad service name - must throw");
 	}
 	catch (ServiceNotFoundException&)
