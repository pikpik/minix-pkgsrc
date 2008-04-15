#	$NetBSD: bsd.dep.mk,v 1.1.1.1 2006/07/14 23:13:00 jlam Exp $

.PHONY:		cleandepend
cleandir: cleandepend

# some of the rules involve .h sources, so remove them from mkdep line
realdepend: beforedepend
.if defined(SRCS)
realdepend: .depend
.NOPATH: .depend
.depend: ${SRCS} ${DPSRCS}
	@rm -f .depend
	@touch .depend
cleandepend:
	rm -f .depend ${.CURDIR}/tags ${CLEANDEPEND}
.else
cleandepend:
.endif
realdepend: afterdepend

beforedepend:
afterdepend:

.if !target(tags)
.if defined(SRCS)
tags: ${SRCS}
	-cd ${.CURDIR}; ctags -f /dev/stdout ${.ALLSRC:N*.h} | \
	    sed "s;\${.CURDIR}/;;" > tags
.else
tags:
.endif
.endif
