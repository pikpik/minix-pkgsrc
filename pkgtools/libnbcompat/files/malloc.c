/*	$NetBSD$	*/

#if ! HAVE_MALLOC
#undef malloc

#include <sys/types.h>

void *malloc();

void *rpl_malloc (size_t n)
{
        if (n == 0) n = 1;
        return malloc(n);
}
#endif
