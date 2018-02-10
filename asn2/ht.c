// This is my code
// Arizza Santos
// CS451 ASN2

#include <stdio.h>
#include <stdlib.h>

#include "misc.h"
#include "list.h"
#include "ht.h"

struct sHashTable
{
  int size;
  tList elements;
  void* (*compare_function) ();
  void* (*hash_function) ();
};
#define HASHT_SIZE (sizeof (struct sHashTable))

tHashTable ht_initialize(int size, int (*compare_function)(),int(*hash_function)())
{
  tHashTable ht = check_malloc(HASHT_SIZE);
  ht->size = size;
  ht->elements = list_initialize();
  ht->compare_function = (void*)compare_function; //casting
  ht->hash_function = (void*)hash_function; //casting
  return ht;
}


void ht_free(tHashTable ht)
{
  list_free(ht->elements);
  free(ht);
  printf("Freeing completed.\n");
}

tHashTable ht_insert(tHashTable ht, void* element)
{

}


tHashTable ht_delete(tHashTable ht, void* element)
{

}

void *ht_lookup(tHashTable ht, void* element)
{

}

void ht_print(tHashTable ht, void (*print_function)())
{

}

void ht_foreach(tHashTable ht, void (*function)(void*))
{

}

void ht_foreach1(tHashTable ht, void (*function)(void* element, void* param1),
                 void* param1)
{

}

void ht_foreach2(tHashTable ht, void (*function)(void* element, void* param1,
                 void* param2), void* param1, void* param2)
{

}

