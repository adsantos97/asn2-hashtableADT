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

  int i;
  for(i=0; i<size; i++)
  {
    ht->buckets[i] = list_initialize();
  }
  ht->size = size;
  ht->compare_funct = compare_function; 
  ht->hash_funct = hash_function;

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
}

tHashTable ht_insert(tHashTable ht, void* element)
{
  int index = ht->hash_funct(element) % ht->size;
  printf("Hashed Index: %d\n", index);
  list_insert_end(ht->buckets[index], element);

  return ht;
}

tHashTable ht_delete(tHashTable ht, void* element)
{
  int index = ht->hash_funct(element) % ht->size;
  printf("Hashed Index: %d\n", index);
  list_remove(ht->buckets[index], element, ht->compare_funct);

  return ht;
}

void *ht_lookup(tHashTable ht, void* element)
{
  int index = ht->hash_funct(element) % ht->size;
  
  list_member(ht->buckets[index], element, ht->compare_funct);

  return element;
}

void ht_print(tHashTable ht, void (*print_function)())
{
  int i;
  for(i=0; i<ht->size; i++)
  {
    printf("Hash Table Index %d: ", i);
    list_foreach(ht->buckets[i], print_function);
    printf("\n");
  } 
}

void ht_foreach(tHashTable ht, void (*function)(void*))
{
  int i;
  for(i=0; i<ht->size; i++)
  {
    list_foreach(ht->buckets[i], function);
  }
}

void ht_foreach1(tHashTable ht, void (*function)(void*, void*),
                 void* param1)
{
  int i;
  for(i=0; i<ht->size; i++)
  {
    list_foreach1(ht->buckets[i], function, param1);
  }
}

void ht_foreach2(tHashTable ht, void (*function)(void*, void*, void*), 
                 void* param1, void* param2)
{
  int i;
  for(i=0; i<ht->size; i++)
  {
    list_foreach2(ht->buckets[i], function, param1, param2);
  }
}

