# $NetBSD$

# the autoconf test for the Darwin linker wrongly succeeds when using
# icc/Linux because icc ignores unknown flags. override this brain
# damage.
.if ${OPSYS} != "Darwin"
CONFIGURE_ENV+=		ac_cv_ld_darwin=no
.endif
