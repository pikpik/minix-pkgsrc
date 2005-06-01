XCOMM $NetBSD$

/*
 * Check the value of BuildRenderLibrary for the presence of
 * Xrender in the X11 distribution.
 */
builtin-test:
#if BuildRenderLibrary
	@echo yes
#else
	@echo no
#endif
