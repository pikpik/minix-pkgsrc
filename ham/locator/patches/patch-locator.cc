--- locator.cc.orig	Fri Jun  3 18:42:09 2011
+++ locator.cc	Fri Jun  3 18:43:13 2011
@@ -3,7 +3,7 @@
 /* Last change 29.07.2001  */
 
 /* A few includes */
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <stdio.h>
 
@@ -19,14 +19,14 @@
   extern int LOCATORtoGPS(char *locator, float *gps_long, float *gps_lat);
 
   /* Initialization */
-  cout << "Locator Ver. " VERSION " by H.M. Stauss, 2001 \n";
+  std::cout << "Locator Ver. " VERSION " by H.M. Stauss, 2001 \n";
   locator=new char[7];
   strcpy(locator,"ZZZZZZ");
 
   if (argc != 2 && argc != 3) {
-    cout << "Converts GPS coordinates to HAM locator or vica versa \n";
-    cout << "Usage: locator XX##YY \n";
-    cout << "       locator Long Lat (in decimal notation) \n";
+    std::cout << "Converts GPS coordinates to HAM locator or vica versa \n";
+    std::cout << "Usage: locator XX##YY \n";
+    std::cout << "       locator Long Lat (in decimal notation) \n";
     goto ende;
   }
 
@@ -36,24 +36,24 @@
     locator[6]='\0';
 
     if(LOCATORtoGPS(locator, &c_long, &c_lat)!=0) {
-      cout << "Locator >>> "<< locator << " <<< is not correct! \n";
+      std::cout << "Locator >>> "<< locator << " <<< is not correct! \n";
       goto ende;
     }
     else {
-      cout << "Locator    : " << locator << "\n";
-      cout << "Coordinates: " <<
+      std::cout << "Locator    : " << locator << "\n";
+      std::cout << "Coordinates: " <<
 	"Long: ";
       if (c_long >0)
-	cout << "(E) ";
+	std::cout << "(E) ";
       else
-	cout << "(W) ";
-      cout  << c_long << " : "<<
+	std::cout << "(W) ";
+      std::cout  << c_long << " : "<<
 	"Lat : ";
       if (c_lat >0)
-	cout << "(N) ";
+	std::cout << "(N) ";
       else
-	cout << "(S) ";
-      cout << c_lat << "\n";
+	std::cout << "(S) ";
+      std::cout << c_lat << "\n";
     }
   }
 
@@ -63,12 +63,12 @@
     sscanf(argv[2],"%f", &c_lat);
 
     if (GPStoLOCATOR(c_long, c_lat, locator)!=0) {
-      cout << "GPS coordinates >>> " << c_long << " : " << c_lat << " <<< wrong! \n";
+      std::cout << "GPS coordinates >>> " << c_long << " : " << c_lat << " <<< wrong! \n";
       goto ende;
     }
     else {
-      cout << "GPS coordinates: " << c_long << " : " << c_lat << "\n";
-      cout << "Locator        : " << locator << "\n";
+      std::cout << "GPS coordinates: " << c_long << " : " << c_lat << "\n";
+      std::cout << "Locator        : " << locator << "\n";
     }
   }
 
