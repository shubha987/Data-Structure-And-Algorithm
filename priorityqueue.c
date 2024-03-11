#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void enqueue(PriorityQueue *queue, int data, int priority) {
    if (queue->size >= MAX_SIZE) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = queue->size - 1;
    while (i >= 0 && queue->elements[i].priority < newElement.priority) {
        queue->elements[i + 1] = queue->elements[i];
        i--;
    }

    queue->elements[i + 1] = newElement;
    queue->size++;
}

int dequeue(PriorityQueue *queue) {
    if (queue->size <= 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = queue->elements[0].data;

    for (int i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }

    queue->size--;

    return data;
}

int main() {
    PriorityQueue queue;
    queue.size = 0;

    enqueue(&queue, 10, 2);
    enqueue(&queue, 20, 1);
    enqueue(&queue, 30, 3);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}