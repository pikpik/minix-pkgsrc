#!@perl@
#
# $NetBSD$
#

use Parallel::Pvm;
use Sys::Hostname;
my $host = hostname();

$ptid = Parallel::Pvm::parent;
Parallel::Pvm::initsend(PvmDataDefault) ;
$buf=Parallel::Pvm::pack("Hi from hello_other.pl running on $host");
Parallel::Pvm::send($ptid,$buf);
Parallel::Pvm::exit;
exit 0;

