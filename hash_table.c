#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TABLE_SIZE 10

typedef struct{
char name[256];
int age;
} person;

person *hash_table[TABLE_SIZE];

int hash(char *name){
  int len = strlen(name);
  unsigned int hash_value = 0;

  for(int i = 0; i < len; i++){
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

void init_hash_table() {
  for(int i = 0; i < TABLE_SIZE: i++){
    hash_table[i] = NULL;
  }
  //table is empty;
}

void print_table() {
  for(int  i=0; i < TABLE_SIZE; i++){
    if(hash_table[i] == NULL)
      printf("\t%d\t_____", i);
    else
      printf("\t%d\t%s", hash_table[i]->name);
  }
}
