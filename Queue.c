#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node* front;
  struct Node* rear;
};

// function to create new node
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// function to initialize queue 
void initializeQueue(struct Queue* queue)
{
  queue->front = queue->rear = NULL;
}

// function to enqueue an element 
void enqueue(struct Queue* queue, int data)
{
  struct Node* newNode = newNode(data);
  if(isEmpty(queue)) {
    queue->front = queue->rear = newNode;
  }
  else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// function to dequeue an element
int dequeue(struct Queue* queue)
{
  if(isEmpty(queue)) {
    printf("queue is empty\n");
    return -1;
  }
  int data = queue->front->data;
  struct Node* temp = queue->front;
  queue->front = queue->front->next;

  free(temp);
  if(queue->front == NULL) {
    queue->rear = NULL;
  }
  return data;
}

// function to peek at front element 
int peek(struct Queue* queue)
{
  if(isEmpty(queue)) {
    printf("queue is empty\n");
    return -1;
  }
  return queue->front->data;
}

// function to check if queue is empty 
int isEmpty(struct Queue* queue)
{
  return queue->front == NULL;
}

int main()
{
  struct Queue queue;
  initializeQueue(&queue);
  enqueue(&queue, 10);
  enqueue(&queue, 20); 
  enqueue(&queue, 30);

  printf("dequeued element: %d\n", dequeue(&queue));
  printf("front element; %d\n", peek(&queue));

  return 0;

}
