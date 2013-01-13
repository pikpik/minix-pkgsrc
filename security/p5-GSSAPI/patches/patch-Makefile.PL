$NetBSD$

--- Makefile.PL.orig	Sun Jan 13 19:52:58 2013
+++ Makefile.PL
@@ -210,7 +210,7 @@ sub find_krb5config_cmd {
    my $r = undef;
    unless ($expl_path) {
       #my $whichcmd =  find_which_command() || die 'cannot locate which command';
-      $r = `which krb5-config 2>/dev/null`;
+      $r = `which krb5-config 2>/dev/null | head -1`;
 
       chomp $r;
       unless ( $r ) {
