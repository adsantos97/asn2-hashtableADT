// This is my code
// Arizza Santos
// CS451 ASN2

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int value;
  int key;
} Node;

void display(Node node[], int size)
{
  int i;
  for(i=0; i < size; i++)
  {
    printf("%d\t%d\n", node[i].value, node[i].key);
  }
}

int main()
{
  int size, i, temp;
  printf("Enter the size of the table: ");
  scanf("%d", &size);
  
  Node hash_table[size];

  printf("Enter the elements: ");
  for(i = 0; i < size; i++)
  {
    scanf("%d", &temp);
    hash_table[temp % size].value = temp;
    hash_table[temp % size].key = temp%size;
  }

  printf("\n");

  display(hash_table, size);

  return 0;
}
