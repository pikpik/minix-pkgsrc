@comment $NetBSD$
lib/echoping/postgresql.la
man/man1/echoping_postgresql.1
@unexec ${RMDIR} %D/lib/echoping 2>/dev/null || ${TRUE}
