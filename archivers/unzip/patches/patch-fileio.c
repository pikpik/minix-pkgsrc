$NetBSD$

--- fileio.c.orig	Mon Apr 20 00:03:44 2009
+++ fileio.c
@@ -1739,6 +1739,7 @@ time_t dos_to_unix_time(dosdatetime)
     DWORD res;
 #else /* ! WIN32 */
 #ifndef BSD4_4   /* GRR:  change to !defined(MODERN) ? */
+#ifndef __minix
 #if (defined(BSD) || defined(MTS) || defined(__GO32__))
     struct timeb tbp;
 #else /* !(BSD || MTS || __GO32__) */
@@ -1746,6 +1747,7 @@ time_t dos_to_unix_time(dosdatetime)
     extern time_t timezone;
 #endif
 #endif /* ?(BSD || MTS || __GO32__) */
+#endif /* !__minix */
 #endif /* !BSD4_4 */
 #endif /* ?WIN32 */
 #endif /* !MACOS && !RISCOS && !QDOS && !TANDEM */
@@ -1805,6 +1807,7 @@ time_t dos_to_unix_time(dosdatetime)
     {
     m_time += 60*(tzinfo.Bias);
 #else /* !WIN32 */
+#ifndef __minix
 #if (defined(BSD) || defined(MTS) || defined(__GO32__))
 #ifdef BSD4_4
     if ( (dosdatetime >= DOSTIME_2038_01_18) &&
@@ -1825,6 +1828,7 @@ time_t dos_to_unix_time(dosdatetime)
     m_time += timezone;         /* seconds WEST of GMT:  add */
 #endif
 #endif /* ?(BSD || MTS || __GO32__) */
+#endif /* ?__minix */
 #endif /* ?WIN32 */
     TTrace((stderr, "  m_time after timezone =  %lu\n", (ulg)m_time));
 
