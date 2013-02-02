$NetBSD$

--- src/components/cpu/M88K_CPUComponent.cc.orig	2010-02-14 09:33:54.000000000 +0000
+++ src/components/cpu/M88K_CPUComponent.cc
@@ -337,7 +337,7 @@ int M88K_CPUComponent::GetDyntransICshif
 }
 
 
-void (*M88K_CPUComponent::GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*) const
+DyntransIC_t M88K_CPUComponent::GetDyntransToBeTranslated() const
 {
 	return instr_ToBeTranslated;
 }
