$NetBSD$

* Avoid to use Gem::RequirePathsBuilder.

--- lib/rubygems/require_paths_builder.rb.orig	2010-06-27 01:41:40.000000000 +0000
+++ lib/rubygems/require_paths_builder.rb
@@ -9,5 +9,4 @@ module Gem::RequirePathsBuilder
       file.puts require_paths
     end
   end
-end
-
+end if false
