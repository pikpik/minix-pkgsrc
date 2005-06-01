XCOMM $NetBSD$

/*
 * Check the value of NormalLibXpm for the presence of Xpm
 * in the X11 distribution.
 */
builtin-test:
#if NormalLibXpm
	@echo yes
#else
	@echo no
#endif
