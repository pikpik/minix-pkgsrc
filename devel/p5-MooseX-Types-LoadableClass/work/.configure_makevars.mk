.if !defined(_MAKEVARS_MK)
_MAKEVARS_MK=	defined

BUILDLINK_PREFIX.perl=	/usr/pkg
BUILDLINK_PREFIX.pthread=	/usr
BUILTIN_LIB_FOUND.c_r=	no
BUILTIN_LIB_FOUND.pthread=	yes
BUILTIN_LIB_FOUND.rt=	yes
H_PTHREAD=	/usr/include/pthread.h
IS_BUILTIN.pthread=	yes
PERL5_SUB_INSTALLARCHLIB=	lib/perl5/5.14.0/x86_64-netbsd-thread-multi
PERL5_SUB_INSTALLSCRIPT=	lib/perl5/bin
PERL5_SUB_INSTALLVENDORARCH=	lib/perl5/vendor_perl/5.14.0/x86_64-netbsd-thread-multi
PERL5_SUB_INSTALLVENDORBIN=	lib/perl5/vendor_perl/bin
PERL5_SUB_INSTALLVENDORLIB=	lib/perl5/vendor_perl/5.14.0
PERL5_SUB_INSTALLVENDORMAN1DIR=	lib/perl5/vendor_perl/man/man1
PERL5_SUB_INSTALLVENDORMAN3DIR=	lib/perl5/vendor_perl/man/man3
PERL5_SUB_INSTALLVENDORSCRIPT=	lib/perl5/vendor_perl/bin
PERLDIR=	/usr/pkg
PKG_BUILD_OPTIONS.perl=	 64bitauto threads
TOOLS_PREFIX.digest=	/usr/pkg
USE_BUILTIN.pthread=	yes
_BLNK_PHYSICAL_PATH.LOCALBASE=	/usr/pkg
_BLNK_PHYSICAL_PATH.WRKDIR=	/var/obj/pkg/devel/p5-MooseX-Types-Common/work
_BLNK_PKG_DBDIR.perl=	/var/db/pkg/perl-5.14.1
_IGNORE_INFO_PATH=	
_MANCOMPRESSED=	no
_MANZ=	no
_PERL5_PREFIX=	/usr/pkg
_PERL5_VARS_OUT=	prefix=/usr/pkg installarchlib=/usr/pkg/lib/perl5/5.14.0/x86_64-netbsd-thread-multi installscript=/usr/pkg/lib/perl5/bin installvendorbin=/usr/pkg/lib/perl5/vendor_perl/bin installvendorscript=/usr/pkg/lib/perl5/vendor_perl/bin installvendorlib=/usr/pkg/lib/perl5/vendor_perl/5.14.0 installvendorarch=/usr/pkg/lib/perl5/vendor_perl/5.14.0/x86_64-netbsd-thread-multi installvendorman1dir=/usr/pkg/lib/perl5/vendor_perl/man/man1 installvendorman3dir=/usr/pkg/lib/perl5/vendor_perl/man/man3
_USE_TOOLS=	[ awk basename cat chgrp chmod chown cmp cp cut date diff digest dirname echo egrep env expr false file find ftp grep gzcat head hostname id install ln ls mkdir mv printf pwd readelf rm rmdir sed sh shlock sleep sort tail tar test touch tr true uname wc xargs
_WRAP_PATH=	/var/obj/pkg/devel/p5-MooseX-Types-Common/work/.buildlink/bin:/var/obj/pkg/devel/p5-MooseX-Types-Common/work/.tools/bin:/usr/pkg/bin:/var/obj/pkg/devel/p5-MooseX-Types-Common/work/.buildlink/bin:/var/obj/pkg/devel/p5-MooseX-Types-Common/work/.tools/bin:/usr/pkg/bin:/home/abs/bin:/sbin:/usr/sbin:/bin:/usr/bin:/usr/X11R7/bin:/usr/local/sbin:/usr/local/bin:/usr/pkg/sbin:/usr/pkg/bin

.endif # _MAKEVARS_MK
