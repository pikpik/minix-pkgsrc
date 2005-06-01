XCOMM $NetBSD$

/*
 * Check the value of BuildGLULibrary for the presence of
 * glu in the X11 distribution.
 */
builtin-test:
#if BuildGLULibrary
	@echo yes
#else
	@echo no
#endif
