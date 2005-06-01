XCOMM $NetBSD$

/*
 * Check the value of BuildXcursorLibrary for the presence of
 * Xcursor in the X11 distribution.
 */
builtin-test:
#if BuildXcursorLibrary
	@echo yes
#else
	@echo no
#endif
