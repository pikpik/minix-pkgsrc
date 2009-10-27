# $NetBSD$

pre-configure: create-xsltproc-wrapper

create-xsltproc-wrapper:
	${PRINTF} "#! ${SH}\\n\
	  ${LOCALBASE}/bin/xsltproc --nonet \$$*\\n\
	" > ${BUILDLINK_DIR}/bin/xsltproc
	${CHMOD} +x ${BUILDLINK_DIR}/bin/xsltproc
