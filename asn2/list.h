/* list.h */

/* copyright (c) David Binkley 2018 */

#ifndef _LIST
#define _LIST


typedef struct sList *tList;

/* exported list functions (you may not need all of these for the assignment) */


tList   list_copy (tList);
void   *list_find(tList, void*, int(*compare)());
void   *list_first(tList);
void    list_foreach(tList, void (*f)());
void    list_foreach1(tList, void (*f)(), void*);
void    list_foreach2(tList, void (*f)(), void*, void*);
void    list_foreach3(tList, void (*f)(), void*, void*, void*);
void    list_foreach4(tList, void (*f)(), void*, void*, void*, void*);
void    list_free(tList);
tList   list_initialize();
tList   list_insert_end(tList, void*);
tList   list_insert_beginning(tList, void*);
tList   list_insert_in_order(tList, void*, int (*compare)());
int     list_isempty(tList);
int 	list_length(tList);
int     list_member(tList, void*, int (*compare)());
void*   list_remove(tList, void*, int (*compare)()); 
void*   list_remove_first(tList);
#define list_remove_any(l) list_remove_first(l)

#endif
