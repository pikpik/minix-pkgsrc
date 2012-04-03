# $NetBSD$
#

# This file needs to be included before replace.mk as it modifies the
# USE_TOOLS variables that are used by replace.mk.
#
.if !empty(USE_TOOLS:Mzip)
USE_TOOLS+=	zipcloak zipnote zipsplit
.elif !empty(USE_TOOLS:Mzip\:run)
USE_TOOLS+=	zipcloak:run zipnote:run zipsplit:run
.endif
