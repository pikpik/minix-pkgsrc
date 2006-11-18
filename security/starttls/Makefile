# $NetBSD$
#

DISTNAME=		starttls-0.10
CATEGORIES=		security
MASTER_SITES=		ftp://opaopa.org/pub/elisp/

MAINTAINER=		fun@naobsd.org
HOMEPAGE=		ftp://opaopa.org/pub/elisp/
COMMENT=		Simple wrapper program for STARTTLS on emacsen

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/emacs.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
