# $NetBSD: libgnutls-extra-config.mk,v 1.1 2009/07/03 11:00:05 drochner Exp $

# Makefile intended to be included by packages that need
# "libgnutls-extra-config" during build time.

USE_TOOLS+=	pkg-config

pre-configure: hack-libgnutls-extra-config

hack-libgnutls-extra-config:
	${PRINTF} "#! ${SH}\\n\
	  case \$$1 in\\n\
	  --cflags|--libs) pkg-config \$$1 gnutls-extra;;\\n\
	  --version) pkg-config --modversion gnutls-extra;;\\n\
	  *) exit 1;;\\n\
	  esac\\n\
	" > ${BUILDLINK_DIR}/bin/libgnutls-extra-config
	${CHMOD} +x ${BUILDLINK_DIR}/bin/libgnutls-extra-config
