# $NetBSD: Makefile,v 1.7 2002/05/15 07:28:51 martti Exp $
#

DISTNAME=	icecast-1.3.12
CATEGORIES=	audio
MASTER_SITES=	http://www.icecast.org/releases/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.icecast.org/
COMMENT=	Internet broadcasting system using Mpeg Layer III streaming

PTHREAD_OPTS+=		native
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-readline \
			--with-libwrap \
			--with-python \
			--with-python-includes=${LOCALBASE}/include \
			--with-python-libraries=${LOCALBASE}/lib
CFLAGS+=		-I${BUILDLINK_DIR}/include/readline

.include "../../devel/readline/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
.  include "../../devel/unproven-pthreads/buildlink.mk"
PGCC=		${CC} -I${BUILDLINK_PREFIX.unproven-pthreads}/pthreads/include
CONFIGURE_ENV+=	CC="${PGCC}"
.endif

.include "../../mk/bsd.pkg.mk"
