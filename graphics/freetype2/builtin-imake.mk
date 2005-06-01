XCOMM $NetBSD$

/*
 * Check the value of BuildFreetype2Library for the presence of
 * freetype2 in the X11 distribution.
 */
builtin-test:
#if BuildFreetype2Library
	@echo yes
#else
	@echo no
#endif
