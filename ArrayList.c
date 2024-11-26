#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int capacity;
  int size;
  int* array;
} ArrayList;

// function to create new array list 
ArrayList* createArrayList(int initialCapacity)
{
  ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
  list->capacity = initialCapacity;
  list->size = 0;
  list->array = (int*)malloc(initialCapacity * sizeof(int));
  return list;
}

// function to add element to end of array list
void add(ArrayList* list, int data)
{
  if(list->size == list->capacity) {
    // double capacity
    list->capacity *= 2;
    list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
  }
  list->array[list->size] = data;
  list->size++;
}

// function to get element at specific index 
int get(ArrayList* list, int index)
{
  if(index < 0 || index >= list->size) {
    printf("index out of bounds\n");
    return -1;
  }
  return list->array[index];
}

// function to set element at a specific index 
void set(ArrayList* list, int index, int data)
{
  if(index < 0 || index >= list->size) {
    printf("index out of bounds\n");
    return;
  }
  list->array[index] = data;
}

// function to remove element at a specific index 
void remove(ArrayList* list, int index)
{
  if(index < 0 || index >= list->size) {
    printf("index out of boudns\n");
    return;
  }
  for(int i = index; i < list->size - 1; i++) {
    list->array[i] = list->array[i + 1];
  }
  list->size--;
}


// function to print array list 
void printArrayList(ArrayList* list)
{
  for(int i = 0; i < list->size; i++) {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}


int main()
{
  ArrayList* list = createArrayList(5);
  add(list, 10);
  add(list, 20);
  add(list, 30);
  add(list, 40);
  add(list, 50);

  printArrayList(list);
  remove(list, 2);
  printArrayList(list);
  return 0;
}
