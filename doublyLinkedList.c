#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head = NULL;

// function to create new node 
struct Node* createNode(int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// function to insert node at beginning
void insertAtBeginning(int data)
{
  struct Node* newNode = createNode(data);
  if(head == NULL) {
    head = newNode;
  }
  else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// function to insert a node at end
void insertAtEnd(int data)
{
  struct Node* newNode = createNode(data);
  if(head == NULL) {
    head = newNode;
  }
  else {
    struct Node* temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

// function to delete from beginning
void deleteFromBeginning()
{
  if(head == NULL) {
    printf("list is empty\n");
    return;
  }
  struct Node* temp = head;
  head = head->next;
  if(head != NULL) {
    head->prev = NULL;
  }
  free(temp);
}

// function to delete node from end
void deleteFromEnd()
{
  if(head == NULL) {
    printf("list is empty\n");
    return;
  }
  struct Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
}

// function to print linked list 
void printList()
{
  struct Node* temp = head;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  insertAtBeginning(10);
  insertAtEnd(20);
  insertAtBeginning(30);

  printList();

  deleteFromBeginning();
  deleteFromEnd();

  printList();

  return 0;
}
