#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef _Queue_h
struct Node;
struct QueueRecord;
typedef struct QueueRecord* Queue;
typedef int ElementType;
typedef struct Node* Position;

int IsEmpty(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
#endif

struct Node {
    ElementType Element;
    Position Next;
};

struct QueueRecord {
    Position Front;
    Position Rear;
};

int IsEmpty(Queue Q) {
    return Q->Front == NULL;
}

Queue CreateQueue(void) {
    Queue TmpCell = (Queue)malloc(sizeof(struct QueueRecord));
    if (TmpCell == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    TmpCell->Front = TmpCell->Rear = NULL;
    return TmpCell;
}

void DisposeQueue(Queue Q) {
    MakeEmpty(Q);
    free(Q);
}

void MakeEmpty(Queue Q) {
    while (Q->Front) {
        Position TmpCell = Q->Front;
        Q->Front = Q->Front->Next;
        free(TmpCell);
    }
    Q->Rear = NULL;
}

void Enqueue(ElementType X, Queue Q) {
    Position TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    TmpCell->Element = X;
    TmpCell->Next = NULL;
    if (IsEmpty(Q)) {
        Q->Front = Q->Rear = TmpCell;
    }
    else {
        Q->Rear->Next = TmpCell;
        Q->Rear = TmpCell;
    }
}

ElementType Front(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    return Q->Front->Element;
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    Position TmpCell = Q->Front;
    Q->Front = Q->Front->Next;
    if (Q->Front == NULL) {
        Q->Rear = NULL;
    }
    free(TmpCell);
}

ElementType FrontAndDequeue(Queue Q) {
    if (IsEmpty(Q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    Position TmpCell = Q->Front;
    ElementType X = TmpCell->Element;
    Q->Front = Q->Front->Next;
    if (Q->Front == NULL) {
        Q->Rear = NULL;
    }
    free(TmpCell);
    return X;
}