$NetBSD$

Fix C++ type error.

--- curses/cursesscreen.C~	2011-08-22 11:36:27.000000000 +0000
+++ curses/cursesscreen.C
@@ -73,7 +73,8 @@ void CursesScreen::KeyReader::operator<<
 	while (input_buf.size() > 0)
 	{
 
-		char *inbuf=&input_buf[0], *outbuf=&winput_buf[winput_cnt];
+		const char *inbuf=&input_buf[0];
+		char *outbuf=&winput_buf[winput_cnt];
 		size_t inbytesleft=input_buf.size(),
 			outbytesleft=winput_buf.size()-winput_cnt;
 
