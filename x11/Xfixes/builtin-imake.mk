XCOMM $NetBSD$

/*
 * Check the value of BuildXfixesLibrary for the presence of
 * Xfixes in the X11 distribution.
 */
builtin-test:
#if BuildXfixesLibrary
	@echo yes
#else
	@echo no
#endif
