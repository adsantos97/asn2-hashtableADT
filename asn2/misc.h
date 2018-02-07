/* misc.h */

/* copyright (c) David Binkley 2018 */

#define printd      if (DEBUG) printf

#ifndef _MISC
#define _MISC

#define TRUE 1
#define FALSE 0
#define BOOLEAN int
#define EQUAL 0

#ifndef NULL
#define NULL 0
#endif


void abort1(char *);
void *check_malloc(int);
void *check_realloc(void *, int);
#endif

