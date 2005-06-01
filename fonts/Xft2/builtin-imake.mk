XCOMM $NetBSD$

/*
 * Check the value of BuildXftLibrary for the presence of
 * Xft2 in the X11 distribution.
 */
builtin-test:
#if BuildXftLibrary
	@echo yes
#else
	@echo no
#endif
