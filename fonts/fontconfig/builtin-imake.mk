XCOMM $NetBSD$

/*
 * Check the value of BuildFontconfigLibrary for the presence of
 * fontconfig in the X11 distribution.
 */
builtin-test:
#if BuildFontconfigLibrary
	@echo yes
#else
	@echo no
#endif
