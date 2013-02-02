$NetBSD$

Fix implicit int.

--- src/glyphs/strchooser/main.c~	2008-05-07 23:07:47.000000000 +0000
+++ src/glyphs/strchooser/main.c
@@ -125,7 +125,7 @@ declareActionCallback(Session)
 declareActionCallback(App)
 implementActionCallback(App)
 
-main(int argc, char *argv[]) {
+int main(int argc, char *argv[]) {
   Session * session =  new Session("strchooser", argc, argv, options, properties);
   LayoutKit &    lk = *LayoutKit::instance();
   WidgetKit *    wk =  MFKit::instance();
