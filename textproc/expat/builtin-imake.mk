XCOMM $NetBSD$

/*
 * Check the value of BuildExpatLibrary for the presence of
 * expat in the X11 distribution.
 */
builtin-test:
#if BuildExpatLibrary
	@echo yes
#else
	@echo no
#endif
