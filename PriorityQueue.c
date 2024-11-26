// PQ allows elements to be inserted with a priority value
// elements are removed in order of priority with the highest priority element being removed first 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int heap_size;
  int array[MAX_SIZE];
} PriorityQueue;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(PriorityQueue* pq, int i)
{
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2; 

  if(left < pq->heap_size && pq->array[left] < pq->array[smallest]) {
    smallest = left;
  }
  if(right < pq->heap_size && pq->array[right] < pq->array[smallest]) {
    smallest = right;
  }
  if(smallest != i) {
    swap(&pq->array[i], &pq->array[smallest]);
    heapify(pq, smallest);
  }
}

void insert(PriorityQueue* pq, int key)
{
  pq->heap_size++;
  pq->array[pq->heap_size - 1] = key;

  int i = pq->heap_size - 1;
  while(i != 0 && pq->array[i] < pq->array[i / 2]) {
    swap(&pq->array[i], &pq->array[i / 2]);
    i = i / 2;
  }
}

int extractMin(PriorityQueue* pq)
{
  if(pq->heap_size <= 0) {
    printf("heap underflow\n");
    return -1;
  }
  int root = pq->array[0];
  pq->array[0] = pq->array[pq->heap_size - 1];
  pq->heap_size--;
  heapify(pq, 0);

  return root;
}

int main()
{
  PriorityQueue pq;
  pq.heap_size = 0; 

  insert(&pq, 10);
  insert(&pq, 5);
  insert(&pq, 15);
  insert(&pq, 3);

  while(pq.heap_size > 0) {
    printf("%d ", extractMin(&pq));
  }
  return 0;
}
