# $NetBSD$
# Override "libltdlc.la" -- the libltdl "convenience" library embedded into
# programs that ship with libltdl.

post-patch: fix-libltdlc
fix-libltdlc:
	${ECHO} 'all install:' >${WRKSRC}/libltdl/Makefile.in
	${ECHO} 'all install:' >${WRKSRC}/libltdl/Makefile
	${RM} -f ${WRKSRC}/libltdl/Makefile.am ${WRKSRC}/libltdl/configure*
	${LN} -fs ${BUILDLINK_DIR}/include/ltdl.h ${WRKSRC}/libltdl/ltdl.h
	${LN} -fs ${BUILDLINK_DIR}/lib/libltdl.la ${WRKSRC}/libltdl/libltdlc.la

.include "../../devel/libltdl/buildlink3.mk"
