$NetBSD$

--- extras/immodules/agent/scim-bridge-agent.cpp.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/agent/scim-bridge-agent.cpp
@@ -198,6 +198,7 @@ ScimBridgeAgent *ScimBridgeAgent::alloc 
 
 ScimBridgeAgentImpl::ScimBridgeAgentImpl ():
 running (true), noexit_enabled (false), standalone_enabled (false), client_app_count (0),
+scim_config_module(0),
 accept_listener (NULL), interruption_listener (NULL), panel_listener (NULL), signal_listener (NULL), display (NULL)
 {
 }
