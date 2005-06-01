XCOMM $NetBSD$

/*
 * Check the value of BuildRandRLibrary for the presence of
 * Xrandr in the X11 distribution.
 */
builtin-test:
#if BuildRandRLibrary
	@echo yes
#else
	@echo no
#endif
