XCOMM $NetBSD$

/*
 * Check the value of BuildCompositeLibrary for the presence of
 * Xcomposite in the X11 distribution.
 */
builtin-test:
#if BuildCompositeLibrary
	@echo yes
#else
	@echo no
#endif
