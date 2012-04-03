$NetBSD$

Use vendordir instead of sitedir.

--- lib/rubygems/defaults.rb.orig	2011-07-27 02:04:03.000000000 +0000
+++ lib/rubygems/defaults.rb
@@ -21,7 +21,7 @@ module Gem
   def self.default_dir
     path = if defined? RUBY_FRAMEWORK_VERSION then
              [
-               File.dirname(ConfigMap[:sitedir]),
+               File.dirname(ConfigMap[:vendordir]),
                'Gems',
                ConfigMap[:ruby_version]
              ]
