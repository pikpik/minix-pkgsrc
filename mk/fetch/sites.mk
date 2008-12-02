# $NetBSD: sites.mk,v 1.50 2008/12/01 11:49:20 obache Exp $
#
# This Makefile fragment defines read-only MASTER_SITE_* variables
# representing some well-known master distribution sites for software.
#

MASTER_SITE_XCONTRIB+=  \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://mirror.switch.ch/mirror/X11/contrib/ \
	ftp://ftp.cica.es/pub/X/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=       \
	http://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.funet.fi/pub/gnu/prep/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/gnu/ \
	ftp://ftp.dti.ad.jp/pub/GNU/ \
	ftp://mirrors.kernel.org/gnu/ \
	ftp://ftp.sunet.se/pub/gnu/ \
	ftp://ftp.lip6.fr/pub/gnu/ \
	ftp://ftp.tuwien.ac.at/linux/gnu/gnusrc/ \
	ftp://ftp.chg.ru/pub/gnu/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/ \
	http://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/

MASTER_SITE_PERL_CPAN+= \
	ftp://cpan.pair.com/modules/by-module/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.gmd.de/mirrors/CPAN/modules/by-module/ \
	ftp://ftp.tuwien.ac.at/pub/CPAN/modules/by-module/ \
	http://cpan.perl.org/CPAN/modules/by-module/ \
	ftp://ftp.fi.muni.cz/pub/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	ftp://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://ftp.tex.ac.uk/tex-archive/ \
	ftp://ftp.dante.de/tex-archive/ \
	ftp://www.t.ring.gr.jp/pub/text/CTAN/ \
	http://www.t.ring.gr.jp/archives/text/CTAN/

MASTER_SITE_SUNSITE+=   \
	ftp://sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/ \
	ftp://ftp.tuwien.ac.at/pub/linux/ibiblio/

MASTER_SITE_GNOME+=     \
	http://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/ \
	ftp://ftp.tuwien.ac.at/hci/GNOME/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/ \
	ftp://ftp.chg.ru/pub/X11/gnome/ \
	ftp://ftp.dit.upm.es/linux/gnome/ \
	ftp://sunsite.mff.cuni.cz/pub/GNOME/

MASTER_SITE_KDE+=	\
	ftp://ftp.kde.org/pub/kde/stable/ \
	ftp://www.t.ring.gr.jp/pub/X/kde/stable/ \
	http://www.t.ring.gr.jp/archives/X/kde/stable/ \
	ftp://ftp.kddlabs.co.jp/pub/X/kde/stable/ \
	ftp://ftp.planetmirror.com.au/pub/kde/stable/ \
	http://public.planetmirror.com/pub/kde/stable/ \
	http://mirrors.isc.org/pub/kde/stable/ \
	ftp://ftp.oregonstate.edu/pub/kde/stable/ \
	ftp://ftp.gtlib.cc.gatech.edu/pub/kde/stable/ \
	ftp://kde.mirrors.tds.net/pub/kde/stable/ \
	ftp://gd.tuwien.ac.at/kde/stable/ \
	ftp://ftp.solnet.ch/mirror/KDE/stable/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/stable/ \
	ftp://mirrors.dotsrc.org/kde/stable/ \
	ftp://ftp.fi.muni.cz/pub/kde/stable/ \
	ftp://ftp.rediris.es/mirror/kde/ftp.kde.org/pub/kde/stable/ \
	http://sunsite.rediris.es/mirror/kde/ftp.kde.org/pub/kde/stable/

# see http://sourceforge.net/project/mirror_picker.php
MASTER_SITE_SOURCEFORGE+=	\
	http://dfn.dl.sourceforge.net/sourceforge/ \
	http://easynews.dl.sourceforge.net/sourceforge/ \
	http://heanet.dl.sourceforge.net/sourceforge/ \
	http://garr.dl.sourceforge.net/sourceforge/ \
	http://internap.dl.sourceforge.net/sourceforge/ \
	http://jaist.dl.sourceforge.net/sourceforge/ \
	http://kent.dl.sourceforge.net/sourceforge/ \
	http://mesh.dl.sourceforge.net/sourceforge/ \
	http://nchc.dl.sourceforge.net/sourceforge/ \
	http://optusnet.dl.sourceforge.net/sourceforge/ \
	http://superb-east.dl.sourceforge.net/sourceforge/ \
	http://superb-west.dl.sourceforge.net/sourceforge/ \
	http://surfnet.dl.sourceforge.net/sourceforge/ \
	http://switch.dl.sourceforge.net/sourceforge/ \
	http://ufpr.dl.sourceforge.net/sourceforge/

MASTER_SITE_SOURCEFORGE_JP+=	\
	http://osdn.dl.sourceforge.jp/ \
	http://jaist.dl.sourceforge.jp/ \
	http://keihanna.dl.sourceforge.jp/ \
	http://globalbase.dl.sourceforge.jp/ \
	http://iij.dl.sourceforge.jp/ \
	http://download.sourceforge.jp/

MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr2.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/

MASTER_SITE_MOZILLA_ALL+=   \
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/

# see http://www.mozilla.org/mirrors.html
MASTER_SITE_MOZILLA+=	\
	http://ftp.mozilla.org/pub/mozilla.org/ \
	ftp://ftp.mozilla.org/pub/mozilla.org/ \
	http://releases.mozilla.org/pub/mozilla.org/ \
	ftp://releases.mozilla.org/pub/mozilla.org/ \
	http://mirror3.mirrors.tds.net/pub/mozilla.org/ \
	http://mozilla.isc.org/pub/mozilla.org/ \
	http://pv-mirror02.mozilla.org/pub/mozilla.org/ \
	http://mirror.uoregon.edu/mozilla/releases/ \
	http://mozilla.mirrors.tds.net/pub/mozilla.org/ \
	http://mirrors.yocum.org/mozilla/ \
	http://mozilla.isohunt.com/ \
	http://mozilla.ussg.indiana.edu/pub/mozilla.org/ \
	http://mirror.atlanticmetro.net/mozilla/ \
	http://mirror.csclub.uwaterloo.ca/pub/mozilla.org/ \
	http://mozilla.mirror.rafal.ca/ \
	http://mirror.cc.vt.edu/pub/mozilla/ \
	http://mirror.its.uidaho.edu/pub/mozilla.org/ \
	http://mozilla.mirror.facebook.com/ \
	http://www.gtlib.gatech.edu/pub/mozilla.org/ \
	http://mozilla.cs.utah.edu/pub/mozilla.org/ \
	http://mirror.mcs.anl.gov/mozilla.org/ \
	http://mirrors.gigenet.com/mozilla/ \
	http://pv-mirror01.mozilla.org/pub/mozilla.org/ \
	http://mozilla-mirror.internap.com/ \
	http://mirror.umoss.org/mozilla/ \
	http://mirrors.xmission.com/mozilla.org/ \
	http://mozilla.mirrors.hoobly.com/ \
	http://ftp.utexas.edu/mozilla/ \
	http://mirrors.enquira.com/mozilla/ \
	http://mozilla.mirror.ac.za/ \
	http://ftp.saix.net/mozilla/ \
	http://kyoto-mz-dl.sinet.ad.jp/pub/mozilla.org/ \
	http://jp-nii01.mozilla.org/pub/mozilla.org/ \
	http://jp-nii02.mozilla.org/pub/mozilla.org/ \
	http://ftp.cs.pu.edu.tw/pub/Mozilla/ \
	http://mozilla.mtk.nao.ac.jp/pub/mozilla.org/ \
	http://ftp.twaren.net/Unix/Mozilla/ \
	http://pj-mirror01.mozilla.org/pub/mozilla.org/ \
	http://mozilla.sakura.ad.jp/pub/mozilla.org/ \
	http://ftp.daum.net/mozilla/ \
	http://mozilla.stu.edu.tw/ \
	http://mozilla.ftp.iij.ad.jp/pub/mozilla/mozilla.org/ \
	http://mozilla-mirror.naist.jp/ \
	http://mirror.kr.freebsd.org/mozilla.org/ \
	http://ftp.isu.edu.tw/pub/Mozilla/ \
	http://mozilla-current.sit.kmutt.ac.th/ \
	http://ftp.kaist.ac.kr/pub/mozilla/ \
	http://ftp.ncnu.edu.tw/mozilla.org/ \
	http://ftp.yz.yamagata-u.ac.jp/pub/network/mozilla/ \
	http://ftp.ntu.edu.tw/pub/mozilla/ \
	http://ftp.kddilabs.jp/Mozilla/ \
	http://mozilla.hongo.wide.ad.jp/pub/mozilla.org/ \
	http://ftp.cgu.edu.tw/Mirror/Mozilla/ \
	http://mozilla.hns.net.in/ \
	http://mozilla.unpad.ac.id/ \
	http://mirror-fpt-telecom.fpt.net/mozilla/ \
	http://mirror.wbut.ac.in/mozilla/ \
	http://mirror.internode.on.net/pub/mozilla/ \
	http://mozilla.mirror.ihug.co.nz/ \
	http://mirror.waia.asn.au/pub/mozilla/ \
	http://mozilla.mirror.pacific.net.au/ \
	http://vlaai.snt.utwente.nl/pub/software/mozilla.org/ \
	http://ftp.sunet.se/pub/www/clients/mozilla.org/ \
	http://mozmirror01.true.nl/pub/mozilla.org/ \
	http://ftp.uni-kl.de/pub/mozilla/ \
	http://mirror.yandex.ru/mozilla/ \
	http://elizabeth.acc.umu.se/pub/mozilla.org/ \
	http://judas.df.lth.se/mozilla/ \
	http://www.mirrorservice.org/sites/releases.mozilla.org/pub/mozilla.org/ \
	http://mozilla.jiddernet.se/ \
	http://sunsite.rediris.es/pub/mozilla.org/ \
	http://www.sdpulse.com/mozilla/ \
	http://ftp.cvut.cz/mozilla/ \
	http://mozilla.kn.vutbr.cz/ \
	http://mirror.switch.ch/ftp/mirror/mozilla/ \
	http://ftp.plusline.de/mozilla/ \
	http://mozilla.miroir-francais.fr/ \
	http://mirror.polymorf.fr/pub/mozilla.org/ \
	http://mozilla.mirrors.skynet.be/pub/ftp.mozilla.org/ \
	http://mozilla.osmirror.nl/ \
	http://mirrors.linux.edu.lv/mozilla.org/ \
	http://www.artfiles.org/mozilla.org/ \
	http://mirrors.xservers.ro/mozilla/ \
	http://ftp.bayanat.com.sa/pub/mirror/ftp.mozilla.org/ \
	http://ftp.spnet.net/mozilla/ \
	http://ftp.ntua.gr/pub/mozilla.org/ \
	http://www.mirrorspace.org/mozilla/ \
	http://ftp.pwr.wroc.pl/pub/mozilla/ \
	http://ftp.heanet.ie/mirrors/ftp.mozilla.org/pub/mozilla.org/ \
	http://mozilla.wpro.lv/ \
	http://mozilla.mirrors.webname.dk/ \
	http://mozilla.spegulo.be/ \
	http://mozilla.nedmirror.nl/ \
	http://mozilla.c3sl.ufpr.br/releases/ \
	http://mozilla.mirror.pop-sc.rnp.br/mirror/mozilla.org/ \
	http://mozilla.localhost.net.ar/ \
	http://mozilla.patan.com.ar/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/ \
	ftp://ftp.pasteur.fr/pub/computing/xemacs/ \
	http://public.planetmirror.com.au/pub/xemacs/ \
	ftp://mirror.aarnet.edu.au/pub/xemacs/ \
	ftp://mirror.cict.fr/xemacs/ \
	ftp://ftp.t.ring.gr.jp/pub/text/xemacs/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/

MASTER_SITE_APACHE+=    \
	http://www.apache.org/dist/ \
	http://www.eu.apache.org/dist/ \
	http://apache.mirror.aussiehq.net.au/ \
	http://apache.oregonstate.edu/ \
	http://www.ibiblio.org/pub/mirrors/apache/ \
	http://mirror.nyi.net/apache/ \
	http://apache.mirrors.tds.net/ \
	http://ftp.unicamp.br/pub/apache/ \
	http://www.mirrorservice.org/sites/ftp.apache.org/ \
	http://gd.tuwien.ac.at/infosys/servers/http/apache/dist/ \
	http://www.meisei-u.ac.jp/mirror/apache/dist/ \
	http://ftp.twaren.net/Unix/Web/apache/ \
	http://ftp.cuhk.edu.hk/pub/packages/apache.org/ \
	ftp://ftp.planetmirror.com.au/pub/apache/dist/ \
	ftp://ftp.oregonstate.edu/pub/apache/ \
	ftp://www.ibiblio.org/pub/mirrors/apache/ \
	ftp://mirror.nyi.net/apache/ \
	ftp://apache.mirrors.tds.net/pub/apache.org/ \
	ftp://ftp.mirrorservice.org/sites/ftp.apache.org/ \
	ftp://gd.tuwien.ac.at/pub/infosys/servers/http/apache/dist/ \
	ftp://ftp.meisei-u.ac.jp/pub/www/apache/dist/ \
	ftp://ftp.twaren.net/Unix/Web/apache/

MASTER_SITE_MYSQL+=	\
	http://mysql.skynet.be/Downloads/ \
	ftp://ftp.mysql.skynet.be/pub/ftp.mysql.com/Downloads/ \
	http://mysql.easynet.be/Downloads/ \
	ftp://ftp.easynet.be/mysql/Downloads/ \
	http://mysql.mirror.kangaroot.net/Downloads/ \
	ftp://mysql.mirror.kangaroot.net/pub/mysql/Downloads/ \
	http://mysql.blic.net/Downloads/ \
	http://mysql.online.bg/Downloads/ \
	ftp://mysql.online.bg/Downloads/ \
	http://mysql.linux.cz/Downloads/ \
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/ \
	http://mirrors.dotsrc.org/mysql/Downloads/ \
	ftp://mirrors.dotsrc.org/mysql/Downloads/ \
	http://mysql.mirrors.webname.dk/Downloads/ \
	http://mysql.borsen.dk/Downloads/ \
	http://mysql.tonnikala.org/Downloads/ \
	http://mir2.ovh.net/ftp.mysql.com/Downloads/ \
	ftp://mir1.ovh.net/ftp.mysql.com/Downloads/ \
	http://mirrors.ircam.fr/pub/mysql/Downloads/ \
	ftp://mirrors.ircam.fr/pub/mysql/Downloads/ \
	ftp://ftp.inria.fr/pub/MySQL/Downloads/ \
	http://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	http://sunsite.informatik.rwth-aachen.de/mysql/Downloads/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/www.mysql.com/Downloads/ \
	ftp://ftp.fu-berlin.de/unix/databases/mysql/Downloads/ \
	http://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	http://ftp.uoi.gr/pub/databases/mysql/Downloads/ \
	ftp://ftp.uoi.gr/pub/databases/mysql/Downloads/ \
	http://mysql.mirrors.crysys.hit.bme.hu/Downloads/ \
	ftp://ftp.crysys.hu/pub/mysql/Downloads/ \
	http://mysql.rhnet.is/Downloads/ \
	ftp://ftp.rhnet.is/pub/mysql/Downloads/ \
	http://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	ftp://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	http://na.mirror.garr.it/mirrors/MySQL/Downloads/ \
	ftp://na.mirror.garr.it/mirrors/MySQL/Downloads/ \
	http://mysql.php.lv/Downloads/ \
	http://mysql.bst.lt/Downloads/ \
	http://mysql.mirrors.webazilla.nl/Downloads/ \
	http://mysql.proserve.nl/Downloads/ \
	ftp://mysql.proserve.nl/pub/mysql/Downloads/Downloads/ \
	http://ftp.tpnet.pl/vol/d3/ftp.mysql.com/Downloads/ \
	ftp://ftp.tpnet.pl/d3/ftp.mysql.com/Downloads/ \
	http://mysql.nfsi.pt/Downloads/ \
	ftp://ftp.nfsi.pt/pub/mysql/Downloads/ \
	http://mirrors.xservers.ro/mysql/Downloads/ \
	ftp://ftp.roedu.net/pub/mirrors/ftp.mysql.com/Downloads/ \
	ftp://mirrors.fibernet.ro/1/MySQL/Downloads/ \
	http://ftp.astral.ro/mirrors/mysql.com/Downloads/ \
	ftp://ftp.astral.ro/mirrors/mysql.com/Downloads/ \
	http://mysql.mix.su/Downloads/ \
	ftp://mysql.mix.su/Downloads/ \
	http://mirrors.paknet.org/mysql/Downloads/ \
	http://www.wsection.com/mysql/Downloads/ \
	http://mirrors.bevc.net/mysql/Downloads/ \
	ftp://ftp.bevc.net/mirrors/mysql/Downloads/ \
	http://mysql.rediris.es/Downloads/ \
	ftp://ftp.rediris.es/mirror/mysql/Downloads/ \
	http://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/ \
	ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/ \
	http://mysql.dataphone.se/Downloads/ \
	ftp://mirror2.dataphone.se/pub/mysql/Downloads/ \
	ftp://ftp.solnet.ch/mirror/mysql/Downloads/ \
	http://mirror.switch.ch/ftp/mirror/mysql/Downloads/ \
	ftp://mirror.switch.ch/mirror/mysql/Downloads/ \
	http://ftp.itu.edu.tr/Mirror/Mysql/Downloads/ \
	ftp://ftp.itu.edu.tr/Mirror/Mysql/Downloads/ \
	http://mysql.infocom.ua/Downloads/ \
	http://mirrors.dedipower.com/www.mysql.com/Downloads/ \
	http://mirrors.ukfast.co.uk/sites/ftp.mysql.com/Downloads/ \
	ftp://mirrors.ukfast.co.uk/ftp.mysql.com/Downloads/ \
	http://www.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	ftp://ftp.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	http://mysql.serenitynet.com/Downloads/ \
	ftp://ftp.mysql.serenitynet.com/Downloads/ \
	http://mysql.mirror.rafal.ca/Downloads/ \
	ftp://mysql.mirror.rafal.ca/pub/mysql/Downloads/ \
	http://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	ftp://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	http://mirror.trouble-free.net/mysql_mirror/Downloads/ \
	http://mysql.llarian.net/Downloads/ \
	ftp://mysql.llarian.net/pub/mysqlDownloads/ \
	http://mysql.mirrors.hoobly.com/Downloads/ \
	http://mysql.osuosl.org/Downloads/ \
	ftp://ftp.osuosl.org/pub/mysql/Downloads/ \
	http://mysql.mirror.redwire.net/Downloads/ \
	ftp://mysql.mirror.redwire.net/pub/mysql/Downloads/ \
	http://mirror.x10.com/mirror/mysql/Downloads/ \
	ftp://mirror.x10.com/mysql/Downloads/ \
	ftp://mirror.anl.gov/pub/mysql/Downloads/ \
	http://mysql.mirrors.pair.com/Downloads/ \
	http://mirror.services.wisc.edu/mysql/Downloads/ \
	ftp://mirror.services.wisc.edu/mirrors/mysql/Downloads/ \
	http://mirrors.24-7-solutions.net/pub/mysql/Downloads/ \
	ftp://mirrors.24-7-solutions.net/pub/mysql/Downloads/ \
	http://mysql.he.net/Downloads/ \
	http://mysql.localhost.net.ar/Downloads/ \
	http://mysql.patan.com.ar/Downloads/ \
	http://mysql.cce.usp.br/Downloads/ \
	ftp://mysql.cce.usp.br/mysqlDownloads/ \
	http://mysql.mirrors.adc.am/Downloads/ \
	http://mysql.mirrors.arminco.com/Downloads/ \
	http://mysql.spd.co.il/Downloads/ \
	http://mirror.mirimar.net/mysql/Downloads/ \
	http://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	ftp://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	http://mirror.pakistani.org/mysql/Downloads/ \
	ftp://mirror.pakistani.org/pub/mysql/Downloads/ \
	http://mysql.byungsoo.net/Downloads/ \
	ftp://mysql.byungsoo.net/pub/mysql/Downloads/ \
	http://mysql.oss.eznetsols.org/Downloads/ \
	ftp://ftp.oss.eznetsols.org/mysql/Downloads/ \
	http://mysql.cs.pu.edu.tw/Downloads/ \
	ftp://ftp.cs.pu.edu.tw/Unix/mysql/Downloads/ \
	http://mysql.isu.edu.tw/Downloads/ \
	http://mysql.ntu.edu.tw/Downloads/ \
	ftp://ftp.ntu.edu.tw/pub/MySQL/Downloads/ \
	http://mysql.cdpa.nsysu.edu.tw/Downloads/ \
	ftp://mysql.cdpa.nsysu.edu.tw/Unix/Database/MySQL/Downloads/ \
	http://mirror-fpt-telecom.fpt.net/mysql/Downloads/ \
	ftp://mirror-fpt-telecom.fpt.net/mirror/mysql/Downloads/ \
	http://mysql.mirror.ac.za/Downloads/ \
	ftp://mysql.mirror.ac.za/Downloads/ \
	http://mysql.inspire.net.nz/Downloads/ \
	ftp://mysql.inspire.net.nz/mysql/Downloads/ \

MASTER_SITE_DEBIAN+= \
	http://ftp.debian.org/debian/ \
	http://ftp.at.debian.org/debian/ \
	http://ftp.au.debian.org/debian/ \
	http://ftp.wa.au.debian.org/debian/ \
	http://ftp.bg.debian.org/debian/ \
	http://ftp.cl.debian.org/debian/ \
	http://ftp.cz.debian.org/debian/ \
	http://ftp.de.debian.org/debian/ \
	http://ftp2.de.debian.org/debian/ \
	http://ftp.ee.debian.org/debian/ \
	http://ftp.es.debian.org/debian/ \
	http://ftp.fi.debian.org/debian/ \
	http://ftp.fr.debian.org/debian/ \
	http://ftp2.fr.debian.org/debian/ \
	http://ftp.uk.debian.org/debian/ \
	http://ftp.hr.debian.org/debian/ \
	http://ftp.ie.debian.org/debian/ \
	http://ftp.is.debian.org/debian/ \
	http://ftp.it.debian.org/debian/ \
	http://ftp.jp.debian.org/debian/ \
	http://ftp.nl.debian.org/debian/ \
	http://ftp.no.debian.org/debian/ \
	http://ftp.nz.debian.org/debian/ \
	http://ftp.pl.debian.org/debian/ \
	http://ftp.ru.debian.org/debian/ \
	http://ftp.se.debian.org/debian/ \
	http://ftp.si.debian.org/debian/ \
	http://ftp.sk.debian.org/debian/ \
	http://ftp.us.debian.org/debian/

MASTER_SITE_OPENOFFICE+=	\
	http://mirrors.isc.org/pub/openoffice/ \
	http://ftp.stardiv.de/pub/OpenOffice.org/ \
	http://openoffice.mirrors.ilisys.com.au/ \
	ftp://ftp.pucpr.br/openoffice/ \
	http://www.ibiblio.org/pub/mirrors/openoffice/ \
	ftp://ftp.ussg.iu.edu/pub/openoffice/ \
	http://openoffice.mirrors.pair.com/ftp/ \
	http://gd.tuwien.ac.at/office/openoffice/ \
	http://ftp.belnet.be/pub/mirror/ftp.openoffice.org/ \
	ftp://ftp.kulnet.kuleuven.ac.be/pub/mirror/openoffice.org/ \
	http://ftp.sh.cvut.cz/MIRRORS/OpenOffice/ \
	ftp://ftp.funet.fi/pub/mirrors/openoffice.org/ \
	ftp://openoffice.cict.fr/openoffice/ \
	http://ftp.club-internet.fr/pub/OpenOffice/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/OpenOffice/ \
	ftp://ftp.tu-chemnitz.de/pub/openoffice/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/ \
	ftp://ftp.join.uni-muenster.de/pub/software/OpenOffice/ \
	http://ftp.ntua.gr/pub/OpenOffice/ \
	http://ftp.fsf.hu/OpenOffice.org/ \
	http://ftp.rhnet.is/pub/OpenOffice/ \
	http://na.mirror.garr.it/mirrors/openoffice/ \
	http://vlaai.snt.utwente.nl/pub/software/openoffice/ \
	http://niihau.student.utwente.nl/openoffice/ \
	http://borft.student.utwente.nl/openoffice/ \
	http://ftp.iasi.roedu.net/mirrors/openoffice.org/ \
	ftp://ftp.arnes.si/packages/OpenOffice.org/ \
	ftp://ftp.saix.net/pub/OpenOffice.org/ \
	http://ftp.rediris.es/ftp/mirror/openoffice.org/ \
	http://ftp.sunet.se/pub/Office/OpenOffice.org/ \
	ftp://mirror.switch.ch/mirror/OpenOffice/ \
	http://mirror.pacific.net.au/openoffice/ \
	http://public.planetmirror.com.au/pub/openoffice/ \
	http://komo.vlsm.org/openoffice/ \
	ftp://ftp.kddlabs.co.jp/office/openoffice/ \
	ftp://ftp.t.ring.gr.jp/pub/misc/openoffice/ \
	http://mymirror.asiaosc.org/openoffice/ \
	ftp://ftp.kr.freebsd.org/pub/openoffice/ \
	http://www.fs.tum.de/~mrauch/OpenOffice/download/

MASTER_SITE_CYGWIN+= \
	http://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	http://mirrors.xmission.com/cygwin/ \
	ftp://ftp.t.ring.gr.jp/pub/pc/gnu-win32/ \
	ftp://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/ \
	http://ifarchive.heanet.ie/if-archive/ \
	http://ifarchive.giga.or.at/if-archive/

### PGSQL list was last updated on 20080823
MASTER_SITE_PGSQL+=	\
	ftp://ftp.ar.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp2.au.postgresql.org/pub/postgresql/ \
	http://ftp.at.postgresql.org/db/www.postgresql.org/pub/ \
	ftp://ftp.at.postgresql.org/db/www.postgresql.org/pub/ \
	http://ftp.be.postgresql.org/postgresql/ \
	ftp://ftp.be.postgresql.org/postgresql/ \
	http://ftp2.be.postgresql.org/ \
	ftp://ftp2.be.postgresql.org/pub/postgresql/ \
	ftp://ftp.ba.postgresql.org/pub/postgresql/ \
	http://ftp2.br.postgresql.org/postgresql/ \
	ftp://ftp2.br.postgresql.org/postgresql/ \
	ftp://ftp3.bg.postgresql.org/postgresql/ \
	ftp://ftp5.ca.postgresql.org/mirrors/postgresql/ \
	ftp://ftp.cn.postgresql.org/pub/postgresql/ \
	http://ftp.cz.postgresql.org/ \
	ftp://ftp.cz.postgresql.org/pgsql/ \
	http://ftp2.cz.postgresql.org/pub/postgresql/ \
	ftp://ftp2.cz.postgresql.org/pub/postgresql/ \
	http://ftp.dk.postgresql.org/postgresql/ \
	ftp://ftp.dk.postgresql.org/postgresql/ \
	http://ftp.ee.postgresql.org/pub/postgresql/ \
	ftp://ftp.ee.postgresql.org/pub/postgresql/ \
	ftp://ftp.fi.postgresql.org/pub/postgresql/ \
	http://ftp3.fr.postgresql.org/pub/postgresql/ \
	ftp://ftp3.fr.postgresql.org/pub/postgresql/ \
	http://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp4.fr.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.fr.postgresql.org/ \
	http://ftp.de.postgresql.org/mirror/postgresql/ \
	ftp://ftp.de.postgresql.org/mirror/postgresql/ \
	http://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	ftp://ftp3.de.postgresql.org/pub/Mirrors/ftp.postgresql.org/ \
	http://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	ftp://ftp8.de.postgresql.org/pub/misc/pgsql/ \
	ftp://ftp7.de.postgresql.org/pub/ftp.postgresql.org/ \
	ftp://ftp9.de.postgresql.org/unix/databases/postgresql/ \
	ftp://ftp10.de.postgresql.org/pub/mirror/postgresql/ \
	http://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp.gr.postgresql.org/pub/databases/postgresql/ \
	http://ftp2.gr.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp2.gr.postgresql.org/pub/databases/postgresql/ \
	http://ftp3.gr.postgresql.org/mirrors/postgresql/ \
	ftp://ftp3.gr.postgresql.org/mirrors/postgresql/ \
	ftp://ftp.is.postgresql.org/pub/postgresql/ \
	http://ftp9.id.postgresql.org/ \
	ftp://ftp9.id.postgresql.org/postgresql/ \
	http://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	ftp://ftp.ie.postgresql.org/mirrors/ftp.postgresql.org/pub/ \
	http://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	ftp://ftp2.ie.postgresql.org/mirrors/ftp.postgresql.org/ \
	ftp://ftp.il.postgresql.org/ftp.postgresql.org/ \
	http://ftp2.it.postgresql.org/mirrors/postgres/ \
	ftp://ftp2.it.postgresql.org/mirrors/postgres/ \
	http://ftp7.it.postgresql.org/pub/unix/postgres/ \
	ftp://ftp7.it.postgresql.org/pub/unix/postgres/ \
	ftp://ftp6.it.postgresql.org/pub/PostgreSQL/ \
	http://ftp2.jp.postgresql.org/pub/postgresql/ \
	http://ftp2.jp.postgresql.org/pub/postgresql/ \
	ftp://ftp2.jp.postgresql.org/pub/postgresql/ \
	http://ftp3.jp.postgresql.org/pub/db/postgresql/ \
	ftp://ftp3.jp.postgresql.org/pub/db/postgresql/ \
	ftp://ftp.kr.postgresql.org/postgresql/ \
	ftp://ftp2.kr.postgresql.org/pub/postgresql/ \
	http://ftp2.lv.postgresql.org/ \
	ftp://ftp2.lv.postgresql.org/postgresql/ \
	ftp://ftp.lv.postgresql.org/mirrors/ftp.postgresql.org/ \
	http://ftp2.lt.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp2.lt.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp.lt.postgresql.org/ \
	ftp://ftp.my.postgresql.org/pub/postgresql/ \
	http://ftp2.nl.postgresql.org/ \
	ftp://ftp2.nl.postgresql.org/mirror/postgresql/ \
	http://ftp4.nl.postgresql.org/ \
	ftp://ftp4.nl.postgresql.org/postgresql.zeelandnet.nl/ \
	ftp://ftp.nl.postgresql.org:21/pub/mirror/postgresql/ \
	ftp://ftp.nz.postgresql.org/postgresql/ \
	ftp://ftp.no.postgresql.org/pub/databases/postgresql/ \
	http://ftp6.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp6.pl.postgresql.org/pub/postgresql/ \
	http://ftp8.pl.postgresql.org/pub/postgresql/ \
	ftp://ftp8.pl.postgresql.org/pub/postgresql/ \
	http://ftp9.pl.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp9.pl.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp7.pl.postgresql.org/pub/mirror/ftp.postgresql.org/ \
	http://ftp.pt.postgresql.org/pub/postgresql/ \
	ftp://ftp.pt.postgresql.org/pub/postgresql/ \
	http://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp6.ro.postgresql.org/pub/mirrors/ftp.postgresql.org/ \
	ftp://ftp7.ro.postgresql.org/1/PostgreSQL/ \
	ftp://ftp.ru.postgresql.org/pub/mirrors/pgsql/ \
	ftp://ftp2.ru.postgresql.org/pub/databases/postgresql/ \
	ftp://ftp3.ru.postgresql.org/pub/mirror/postgresql/pub/ \
	ftp://ftp2.sk.postgresql.org/pub/postgresql/ \
	ftp://ftp.si.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.za.postgresql.org/mirror/ftp.postgresql.org/ \
	http://ftp5.es.postgresql.org/mirror/postgresql/ \
	ftp://ftp5.es.postgresql.org/mirror/postgresql/ \
	http://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	ftp://ftp.se.postgresql.org/pub/databases/relational/postgresql/ \
	http://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp2.ch.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp.ch.postgresql.org/mirror/postgresql/ \
	http://ftp3.tw.postgresql.org/postgresql/ \
	ftp://ftp3.tw.postgresql.org/postgresql/ \
	http://ftp4.tw.postgresql.org/pub/postgresql/ \
	ftp://ftp4.tw.postgresql.org/pub/postgresql/ \
	ftp://ftp.tw.postgresql.org/pub/postgresql/ \
	ftp://ftp.tr.postgresql.org/pub/PostgreSQL/ \
	http://ftp7.us.postgresql.org/pub/postgresql/ \
	ftp://ftp7.us.postgresql.org/pub/postgresql/ \
	http://ftp9.us.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp9.us.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp5.us.postgresql.org/pub/PostgreSQL/ \
	ftp://ftp10.us.postgresql.org/pub/postgresql/ \
	ftp://ftp11.us.postgresql.org/pub/mirrors/postgresql/ \
	ftp://ftp2.ua.postgresql.org/pub/postgresql/ \
	ftp://ftp3.ua.postgresql.org/pub/mirrors/postgresql/ \
	http://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/ \
	ftp://ftp2.uk.postgresql.org/sites/ftp.postgresql.org/ \
	ftp://ftp.vn.postgresql.org/mirror/postgresql/

MASTER_SITE_GENTOO+= \
	http://distfiles.gentoo.org/ \
	ftp://gentoo.arcticnetwork.ca/pub/gentoo/ \
	http://gentoo.arcticnetwork.ca/source/ \
	ftp://mirrors.tera-byte.com/pub/gento/ \
	http://gentoo.mirrors.tera-byte.com/ \
	ftp://mirror.csclub.uwaterloo.ca/gentoo-distfiles/ \
	http://mirror.csclub.uwaterloo.ca/gentoo-distfiles/ \
	http://mirror.mcs.anl.gov/pub/gentoo/ \
	ftp://mirror.mcs.anl.gov/pub/gentoo/ \
	http://gentoo.binarycompass.org/ \
	ftp://gentoo.chem.wisc.edu/gentoo/ \
	http://gentoo.chem.wisc.edu/gentoo/ \
	http://mirrors.cs.wmich.edu/gento/ \
	http://mirror.datapipe.net/gento/ \
	ftp://mirror.datapipe.net/gento/ \
	http://gentoo.mirrors.easynews.com/linux/gentoo/ \
	http://mirror.fslutd.org/linux/distributions/gentoo/ \
	ftp://mirror.fslutd.org/linux/distributions/gentoo/ \
	ftp://ftp.gtlib.gatech.edu/pub/gento/ \
	http://www.gtlib.gatech.edu/pub/gento/ \
	http://gentoo.mirrors.hoobly.com/ \
	ftp://distro.ibiblio.org/pub/linux/distributions/gentoo/ \
	http://distro.ibiblio.org/pub/linux/distributions/gentoo/ \
	ftp://ftp.ussg.iu.edu/pub/linux/gento/ \
	ftp://lug.mtu.edu/gentoo/ \
	http://lug.mtu.edu/gentoo/ \
	http://gentoo.netnitco.net/ \
	ftp://gentoo.netnitco.net/pub/mirrors/gentoo/source/ \
	http://open-systems.ufl.edu/mirrors/gento/ \
	http://gentoo.osuosl.org/ \
	http://gentoo.mirrors.pair.com/ \
	ftp://gentoo.mirrors.pair.com/ \
	ftp://mirror.iawnet.sandia.gov/pub/gentoo/ \
	http://gentoo.llarian.net/ \
	ftp://gentoo.llarian.net/pub/gento/ \
	http://gentoo.mirrors.tds.net/gento/ \
	ftp://gentoo.mirrors.tds.net/gento/ \
	ftp://ftp.ucsb.edu/pub/mirrors/linux/gentoo/ \
	http://ftp.ucsb.edu/pub/mirrors/linux/gentoo/ \
	http://cudlug.cudenver.edu/gentoo/ \
	http://gentoo.cites.uiuc.edu/pub/gentoo/ \
	ftp://gentoo.cites.uiuc.edu/pub/gentoo/ \
	http://mirror.usu.edu/mirrors/gentoo/ \
	ftp://ftp.wallawalla.edu/pub/mirrors/ftp.gentoo.or/ \
	http://gentoo.localhost.net.ar/ \
	ftp://mirrors.localhost.net.ar/pub/mirrors/gento/ \
	http://www.las.ic.unicamp.br/pub/gentoo/ \
	ftp://ftp.las.ic.unicamp.br/pub/gentoo/ \
	http://gentoo.inode.at/ \
	ftp://gentoo.inode.at/source/ \
	http://gd.tuwien.ac.at/opsys/linux/gentoo/ \
	ftp://gd.tuwien.ac.at/opsys/linux/gentoo/ \
	http://mirror.bih.net.ba/gentoo/ \
	ftp://mirror.bih.net.ba/gentoo/ \
	http://distfiles.gentoo.bg/ \
	http://ftp.gentoo.bg/ \
	http://mirrors.ludost.net/gentoo/ \
	ftp://mirrors.ludost.net/gentoo/ \
	http://gentoo.supp.name/ \
	http://ftp.fi.muni.cz/pub/linux/gentoo/ \
	ftp://ftp.fi.muni.cz/pub/linux/gentoo/ \
	http://gentoo.mirror.dkm.cz/pub/gentoo/ \
	ftp://gentoo.mirror.dkm.cz/pub/gentoo/ \
	http://gentoo.mirror.web4u.cz/ \
	ftp://gentoo.mirror.web4u.cz/ \
	http://mirror.uni-c.dk/pub/gentoo/ \
	ftp://ftp.klid.dk/gentoo/ \
	http://ftp.klid.dk/ftp/gentoo/ \
	http://ftp.linux.ee/pub/gentoo/distfiles/ \
	ftp://ftp.linux.ee/pub/gentoo/distfiles/ \
	http://trumpetti.atm.tut.fi/gentoo/ \
	ftp://trumpetti.atm.tut.fi/gentoo/ \
	ftp://ftp.first-world.info/ \
	http://ftp.first-world.info/ \
	ftp://ftp.free.fr/mirrors/ftp.gentoo.org/ \
	ftp://gentoo.imj.fr/pub/gentoo/ \
	http://mirror.ovh.net/gentoo-distfiles/ \
	ftp://mirror.ovh.net/gentoo-distfiles/ \
	ftp://de-mirror.org/distro/gentoo/ \
	http://de-mirror.org/distro/gentoo/ \
	ftp://ftp.wh2.tu-dresden.de/pub/mirrors/gento/ \
	ftp://ftp.gentoo.mesh-solutions.com/gentoo/ \
	http://gentoo.mneisen.org/ \
	http://linux.rz.ruhr-uni-bochum.de/download/gentoo-mirror/ \
	ftp://linux.rz.ruhr-uni-bochum.de/gentoo-mirror/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gento/ \
	http://mirrors.sec.informatik.tu-darmstadt.de/gentoo/ \
	ftp://pandemonium.tiscali.de/pub/gentoo/ \
	ftp://ftp.tu-clausthal.de/pub/linux/gentoo/ \
	http://ftp.uni-erlangen.de/pub/mirrors/gento/ \
	ftp://ftp.uni-erlangen.de/pub/mirrors/gento/ \
	http://ftp6.uni-erlangen.de/pub/mirrors/gento/ \
	ftp://ftp6.uni-erlangen.de/pub/mirrors/gento/ \
	ftp://ftp.join.uni-muenster.de/pub/linux/distributions/gento/ \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/gentoo/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/gentoo/ \
	ftp://ftp.ipv6.uni-muenster.de/pub/linux/distributions/gento/ \
	ftp://ftp6.uni-muenster.de/pub/linux/distributions/gento/ \
	ftp://files.gentoo.gr/ \
	http://files.gentoo.gr/ \
	ftp://ftp.ntua.gr/pub/linux/gentoo/ \
	http://ftp.ntua.gr/pub/linux/gentoo/ \
	ftp://ftp.cc.uoc.gr/mirrors/linux/gentoo/ \
	http://ftp.cc.uoc.gr/mirrors/linux/gentoo/ \
	ftp://ftp.uoi.gr/mirror/OS/gentoo/ \
	http://ftp.uoi.gr/mirror/OS/gentoo/ \
	http://gentoo.inf.elte.hu/ \
	ftp://gentoo.inf.elte.hu/ \
	http://ftp.rhnet.is/pub/gentoo/ \
	ftp://ftp.rhnet.is/pub/gentoo/ \
	http://ftp.heanet.ie/pub/gentoo/ \
	ftp://ftp.heanet.ie/pub/gentoo/ \
	http://mirror.hamakor.org.il/pub/mirrors/gentoo/ \
	ftp://ftp.unina.it/pub/linux/distributions/gento/ \
	http://gentoo.tups.lv/source/ \
	http://mirror.muntinternet.net/pub/gentoo/ \
	ftp://mirror.muntinternet.net/pub/gentoo/ \
	http://gentoo.tiscali.nl/ \
	ftp://gentoo.tiscali.nl/pub/mirror/gentoo/ \
	http://ftp.snt.utwente.nl/pub/os/linux/gento/ \
	ftp://ftp.snt.utwente.nl/pub/os/linux/gento/ \
	http://ftp.snt.ipv6.utwente.nl/pub/os/linux/gentoo/ \
	ftp://ftp.snt.ipv6.utwente.nl/pub/os/linux/gentoo/ \
	http://mirror.gentoo.no/ \
	http://gentoo.zie.pg.gda.pl/ \
	ftp://mirror.icis.pcz.pl/gentoo/ \
	http://gentoo.prz.rzeszow.pl/ \
	http://gentoo.po.opole.pl/ \
	ftp://gentoo.po.opole.pl/ \
	http://ftp.vectranet.pl/gentoo/ \
	ftp://ftp.vectranet.pl/gentoo/ \
	http://gentoo.mirror.pw.edu.pl/ \
	http://darkstar.ist.utl.pt/gentoo/ \
	ftp://darkstar.ist.utl.pt/pub/gentoo/ \
	ftp://ftp.rnl.ist.utl.pt/pub/gentoo/ \
	ftp://cesium.di.uminho.pt/pub/gentoo/ \
	http://cesium.di.uminho.pt/pub/gentoo/ \
	ftp://ftp.dei.uc.pt/pub/linux/gentoo/ \
	http://ftp.dei.uc.pt/pub/linux/gentoo/ \
	http://mirrors.evolva.ro/gentoo/ \
	ftp://mirrors.evolva.ro/gentoo/ \
	http://ftp.roedu.net/pub/mirrors/gentoo.org/ \
	ftp://ftp.roedu.net/pub/mirrors/gentoo.org/ \
	ftp://ftp.romnet.org/gentoo/ \
	http://ftp.romnet.org/gentoo/ \
	http://mirrors.xservers.ro/gentoo/ \
	http://mirror.yandex.ru/gentoo-distfiles/ \
	ftp://mirror.yandex.ru/gentoo-distfiles/ \
	http://gentoo.ynet.sk/pu/ \
	http://gentoo-euetib.upc.es/mirror/gentoo/ \
	http://ftp.udc.es/gentoo/ \
	ftp://ftp.udc.es/gentoo/ \
	ftp://ftp.ds.karen.hj.se/gentoo/ \
	http://ftp.ds.karen.hj.se/gentoo/ \
	ftp://ftp.ing.umu.se/linux/gentoo/ \
	http://ftp.ing.umu.se/linux/gentoo/ \
	ftp://mirror.mdfnet.se/gento/ \
	http://mirror.mdfnet.se/mirror/gento/ \
	http://mirror.switch.ch/ftp/mirror/gentoo/ \
	ftp://mirror.switch.ch/mirror/gentoo/ \
	http://ftp.ankara.edu.tr/gentoo/ \
	ftp://ftp.ankara.edu.tr/gentoo/ \
	ftp://mirror.bytemark.co.uk/gentoo/ \
	http://mirror.bytemark.co.uk/gentoo/ \
	http://mirror.qubenet.net/mirror/gentoo/ \
	ftp://mirror.qubenet.net/mirror/gentoo/ \
	http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/ \
	ftp://ftp.mirrorservice.org/sites/www.ibiblio.org/gentoo/ \
	http://gentoo.virginmedia.com/ \
	ftp://gentoo.virginmedia.com/sites/gento/ \
	http://mirror.pacific.net.au/linux/Gento/ \
	ftp://mirror.pacific.net.au/linux/Gento/ \
	ftp://ftp.swin.edu.au/gento/ \
	http://ftp.swin.edu.au/gento/ \
	http://gentoo.channelx.biz/ \
	http://gentoo.gg3.net/ \
	ftp://gg3.net/pub/linux/gentoo/ \
	http://ftp.iij.ad.jp/pub/linux/gentoo/ \
	ftp://ftp.iij.ad.jp/pub/linux/gentoo/ \
	http://ftp.jaist.ac.jp/pub/Linux/Gentoo/ \
	ftp://ftp.jaist.ac.jp/pub/Linux/Gentoo/ \
	ftp://ftp.ecc.u-tokyo.ac.jp/GENTO/ \
	http://ftp.daum.net/gentoo/ \
	ftp://ftp.daum.net/gentoo/ \
	http://ftp.kaist.ac.kr/pub/gentoo/ \
	ftp://ftp.kaist.ac.kr/gentoo/ \
	http://ftp.lecl.net/pub/gentoo/ \
	ftp://ftp.lecl.net/pub/gentoo/ \
	http://ftp.twaren.net/Linux/Gentoo/ \
	ftp://ftp.twaren.net/Linux/Gentoo/ \
	ftp://ftp.ncnu.edu.tw/Linux/Gentoo/ \
	http://ftp.ncnu.edu.tw/Linux/Gentoo/ \
	ftp://gentoo.cs.nctu.edu.tw/gentoo/ \
	http://gentoo.cs.nctu.edu.tw/gentoo/ \
	ftp://ftp.cs.pu.edu.tw/Linux/Gentoo/ \
	http://ftp.cs.pu.edu.tw/Linux/Gentoo/ \
	http://mirrors.64hosting.com/pub/mirrors/gentoo/ \
	ftp://mirrors.64hosting.com/pub/mirrors/gentoo/ \
	http://gentoo.kems.net/ \
	ftp://gentoo.kems.net/mirrors/gento/

MASTER_SITE_XORG+= \
	http://xorg.freedesktop.org/releases/individual/ \
	ftp://ftp.x.org/pub/individual/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/individual/ \
	ftp://sunsite.uio.no/pub/X11/individual/

MASTER_SITE_FREEBSD+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.fi.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	http://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/
