# $NetBSD$
#
# Makefiles are defaulting to /usr/pkg/bin/bmake which doesn't link the
# pfstatd executable on DragonFly.  /usr/bin/make works outside of the
# build environment but not inside it, so some environment variable seems
# to be interfering.
#
.if ${OPSYS} == "DragonFly"
post-build:
	cd ${WRKSRC}/pfstatd && \
	  ${CC} -O -pipe -Wall -I.. -g -std=gnu99 -o pfstatd pfstatd.o pf.o
.endif
