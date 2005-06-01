XCOMM $NetBSD$

/*
 * Check the value of BuildGLXLibrary for the presence of
 * MesaLib in the X11 distribution.
 */
builtin-test:
#if BuildGLXLibrary
	@echo yes
#else
	@echo no
#endif
