#pragma once
#include <malloc.h>
#ifndef _BinHeap_H
#define MinPQSize 1
#define MinData 0
typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize(int MaxElemts);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType* Elements;
};

PriorityQueue Initialize(int MaxElemts) {
	PriorityQueue H;
	if (MaxElemts < MinPQSize) throw("too small");

	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL) throw("OUT OF SPACE");

	H->Elements = (ElementType*)malloc((MaxElemts + 1) * sizeof(ElementType));
	if (H->Elements == NULL)throw("OUT OF SPACE");

	H->Capacity = MaxElemts;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;
}

void Destory(PriorityQueue H) {
	H->Capacity = 0;
	free(H->Elements);
	H->Size = 0;
}

void MakeEmpty(PriorityQueue H) {
	free(H->Elements);
	H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H) {
	if (IsFull(H)) {
		throw("OUT OF SPACE");
		return;
	}
	int i;
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) H->Elements[i] = H->Elements[i / 2];//上浮找到一个合适的空位
	H->Elements[i] = X;
	return;
}

ElementType DeleteMin(PriorityQueue H) {
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H)) {
		throw("OUT OF SAPCE");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = Child) {
		Child = i * 2;
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) Child++;
		if (LastElement > H->Elements[Child])H->Elements[i] = H->Elements[Child];
		else break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}

int IsEmpty(PriorityQueue H) {
	if (H->Size == 0)return 1;
	return 0;
}

int IsFull(PriorityQueue H) {
	if (H->Size == H->Capacity)return 1;
	return 0;
}