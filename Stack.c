#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Stack {
  struct Node* top;
};

// function to create a new node
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// function to initialize stack 
void initializeStack(struct Stack* stack)
{
  stack->top = NULL;
}

// function to push element onto stack 
void push(struct Stack* stack, int data)
{
  struct Node* newNode = newNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
}

// function to pop an element from stack 
int pop(struct Stack* stack)
{
  if(isEmpty(stack)) {
    printf("stack is empty\n");
    return -1;
  }
  int data = stack->top->data;
  struct Node* temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

// function to peek at top element
int peek(struct Stack* stack) {
    if(isEmpty(stack)) {
      printf("stack is empty\n");
      return -1;
    }
    return stack->top->data;
}

// function to check if stack is empty 
int isEmpty(struct Stack* stack)
{
  return stack->top == NULL;
}

int main()
{
  struct Stack stack;
  initializeStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("popped element: %d\n", pop(&stack));
  printf("top elemetn: %d\n", peek(&stack));

  return 0;
}
