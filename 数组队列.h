#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef _Queue_h
struct QueueRecord;
typedef struct QueueRecord* Queue;
typedef int ElementType;
int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
#endif

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType* Array;
};

int IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Capacity == Q->Size;
}

Queue CreateQueue(int MaxElements) {
    Queue TmpCell = (Queue)malloc(sizeof(struct QueueRecord));
    if (TmpCell == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    TmpCell->Capacity = MaxElements;
    TmpCell->Size = 0;
    TmpCell->Front = 0;
    TmpCell->Rear = 0;
    TmpCell->Array = (ElementType*)malloc(sizeof(ElementType) * MaxElements);
    if (TmpCell->Array == NULL) {
        fprintf(stderr, "Out of memory.\n");
        free(TmpCell);
        exit(1);
    }
    return TmpCell;
}

void DisposeQueue(Queue Q) {
    free(Q->Array);
    free(Q);
}

void MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 0;
    Q->Rear = 0;
}

void Enqueue(ElementType X, Queue Q) {
    if (IsFull(Q)) {
        fprintf(stderr, "Out of Space\n");
        return;
    }
    Q->Array[Q->Rear] = X;
    Q->Rear = (Q->Rear + 1) % Q->Capacity; // Circular queue
    Q->Size++;
}

ElementType Front(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        return;
    }
    Q->Front = (Q->Front + 1) % Q->Capacity; // Circular queue
    Q->Size--;
}

ElementType FrontAndDequeue(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    ElementType X = Q->Array[Q->Front];
    Q->Front = (Q->Front + 1) % Q->Capacity; // Circular queue
    Q->Size--;
    return X;
}