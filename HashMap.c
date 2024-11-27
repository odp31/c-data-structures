// stores key-value pairs; uses a hash function to map keys to indices in an array

// c implementation of a hash map using a simple hash function and separate chaining for collision handling

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
  int key;
  int value;
  struct Node* next;
} Node;

typedef struct HashMap {
  Node* table[TABLE_SIZE];
} HashMap;

// simple hash function
int hash(int key) {
  return key % TABLE_SIZE;
}
// create new node
Node* createNode(int key, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

// insert key value pair into hash map
void insert(HashMap* hashTable, int key, int value) {
  int index = hash(key);
  Node* head = hashTable->table[index];

  // check if key already exists
  while(head != NULL) {
    if(head->key == key) {
      head->value = value;
      return;
    }
    head = head->next;
  }
  // create new node and insert at beginning
  Node* newNode = createNode(key, value);
  newNode->next = hashTable->table[index];
  hashTable->table[index] = newNode;
}

// search for key in hash map
int search(HashMap* hashTable, int key) {
  int index = hash(key);
  Node* head = hashTable->table[index];
  while(head!= NULL){
    if(head->key == key) {
      return head->value;
    }
    head = head->next;
  }
  return -1; // key not found
}
// delete key value pair from hash map
void deleteKey(HashMap* hashTable, int key)
{
  int index = hash(key);
  Node* head = hashTable->table[index];
  Node* prev = NULL;

  while(head != NULL) {
    if(head->key == key) {
      if(prev== NULL) {
        hashTable->table[index] = head->next;
      }
      else {
        prev->next = head->nxt;
      }
      free(head);
      return;
    }
    prev = head;
    head = head->next;
  }
}

int main()
{
  HashMap hashTable;
  for(int i = 0; i < TABLE_SIZE; i++) {
    hashTable.table[i] = NULL;
  }
  insert(&hashTable, 10, 20);
  insert(&hashTable, 20, 30);
  insert(&hashTable, 30, 40);

  printf("value of key 20: %d\n", search(&hashTable, 20));
  deleteKey(&hashTable, 20);
  printf("value of key 20 after deletion: %d\n", search(&hashTable, 20));
  return 0;
}
