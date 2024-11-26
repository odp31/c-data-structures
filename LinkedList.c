#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct LinkedList {
  struct Node* head;
  struct Node* tail;
  int size;
};

// function to create new node
struct Node* createNode(int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// function to initalize linked list
void initializeList(struct LinkedList* list)
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// function to insert a node at beginning 
void insertAtBeginning(struct LinkedList* list, int data)
{
  struct Node* newNode = createNode(data);
  if(list->head == NULL){
    list->head = list->tail = newNode;
  }
  else{
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
  }
  list->size++;
}

// function to insert a node at the end
void insertAtEnd(struct LinkedList* list, int data)
{
  struct Node* newNode = createNode(data);
  if(list->head == NULL) {
    list->head = list->tail = newNode;
  }
  else{
    list->tail->next = newNode;
    newNode->prev = list-> tail;
    list->tail = newNode;
  }
  list->size++;
}

// function to delete node from beginning
void deleteFromBeginning(struct LinkedList* list)
{
  if(list->head == NULL) {
    printf("list is empty\n");
    return;
  }
  struct Node* temp = list->head;
  list->head = list->head->next;
  if(list->head != NULL) {
    list->head->prev = NULL;
  }
  else {
    list->tail = NULL;
  }
  free(temp);
  list->size--;
}

// function to delete node from end 
void deleteFromEnd(struct LinkedList* list)
{
  if(list->head == NULL) {
    printf("list is empty\n");
    return;
  }
  struct Node* temp = list->tail;
  list->tail = list->tail->prev;
  if(list->tail != NULL) {
    list->tail->next = NULL;
  }
  else {
    list->head = NULL;
  }
  free(temp);
  list->size--;
}

// function to print linkedlist
void printList(struct LinkedList* list)
{
  struct Node* current = list->head;
  while(current != NULL) {
    printf("%d", current->data);
    current = current-> next;
  }
  printf("\n");
}

int main()
{
  struct LinkedList list;
  initializeList(&list);

  insertAtEnd(&list, 10);
  insertAtBeginning(&list, 20);
  insertAtEnd(&list, 30);

  printList(&list);

  deleteFromBeginning(&list);
  deleteFromEnd(&list);

  printList(&list);

  return 0;
}
