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
  int (*compare_funct) ();
  int (*hash_funct) ();
};
#define HASHT_SIZE (sizeof (struct sHashTable))

typedef struct sHashTable *tHashTable;

tHashTable ht_initialize(int size, int (*compare_function)(), int (*hash_function)())
{
  if (size < 1) return NULL;

  tHashTable ht = check_malloc(HASHT_SIZE);
  ht->size = size;
  ht->elements = list_initialize();
  ht->compare_funct = compare_function; 
  ht->hash_funct = hash_function;

  return ht;
}

void ht_free(tHashTable ht)
{
  list_free(ht->elements);
  free(ht);
  //printf("Freeing completed.\n");
}

tHashTable ht_insert(tHashTable ht, void* element)
{
  int hash = (int)ht->hash_funct;
  int key = hash % ht->size;
  
  ht = list_insert_end(ht->elements, element);
}

tHashTable ht_delete(tHashTable ht, void* element)
{

}

void *ht_lookup(tHashTable ht, void* element)
{

}

void ht_print(tHashTable ht, void (*print_function)())
{
  int i;

  for(i=0; i<; i++)
  {
    print_function();
  }
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

