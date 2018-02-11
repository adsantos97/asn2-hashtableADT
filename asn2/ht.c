// This is my code
// Arizza Santos
// CS451 ASN2

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "ht.h"
#include "misc.h"

struct sHashTable
{
  int size;
  tList *buckets;
  int (*compare_funct) ();
  int (*hash_funct) ();
};
#define HASHT_SIZE (sizeof (struct sHashTable))

tHashTable ht_initialize(int size, int (*compare_function)(), int (*hash_function)())
{
  if (size < 1) return NULL;

  tHashTable ht = check_malloc(HASHT_SIZE);
  ht->buckets = check_malloc(sizeof(tList)*size);

  /*int i;
  for(i=0; i<size; i++)
  {
    ht->buckets[i] = list_initialize();
  }*/
  //ht->buckets = list_initialize();
  ht->size = size;
  ht->compare_funct = compare_function; 
  ht->hash_funct = hash_function;

  //printf("%d\n", ht->size);

  return ht;
}

void ht_free(tHashTable ht)
{
  int i;
  for(i=0; i<ht->size; i++)
  {
    list_free(ht->buckets[i]);
  }
  free(ht);
  //printf("Freeing completed.\n");
}

tHashTable ht_insert(tHashTable ht, void* element)
{
  int hash = ht->hash_funct();
  printf("hash: %d\n", hash);
  int index = hash % ht->size;  
  printf("index: %d\n", index);

  list_insert_end(ht->buckets[index], element);

  return ht;
}

tHashTable ht_delete(tHashTable ht, void* element)
{

}

void *ht_lookup(tHashTable ht, void* element)
{

}

void ht_print(tHashTable ht, void (*print_function)())
{
  /*int i;
  for (i=0; i<ht->size; i++)
  {
    while(ht->
  } */ 
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

