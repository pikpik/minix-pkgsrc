# $NetBSD$
#

PKGNAME=	${DISTNAME:S/crudesaml-/pam-saml-/}
COMMENT=	Crude SAML assertion validator for bridging WebSSO and PAM

PKG_DESTDIR_SUPPORT=    user-destdir

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/security
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} pam_saml.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_MAN} ${WRKSRC}/pam_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
