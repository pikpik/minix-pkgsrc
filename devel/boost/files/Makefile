# $NetBSD: Makefile,v 1.4 2000/11/03 00:16:32 jlam Exp $

CXX?=		c++

LIB=		libboost.la

CXXFLAGS+=	# empty
CPPFLAGS+=	-I${.CURDIR} -I${LOCALBASE}/include/sgi-stl

all:	${LIB}

${LIB}:
	${LIBTOOL} ${CXX} ${CXXFLAGS} -o ${.TARGET} ${LOBJS} \
		-rpath ${PREFIX}/lib -version-info ${BOOST_VERS}
