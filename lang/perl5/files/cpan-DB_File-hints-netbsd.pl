# $NetBSD$

# cpan/DB_File:
# NetBSD does not provide -ldb, so avoid linking to it

$self->{LIBS} = [''];
