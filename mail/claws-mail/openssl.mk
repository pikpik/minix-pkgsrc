# $NetBSD:$
#

# for SMTP, POP3 and IMAP over SSL
# set these just in case we don't have a pkg-config file for openssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"
