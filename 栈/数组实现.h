#pragma once
#include <cstddef>
#include <malloc.h>
#ifndef _Stakc_h
typedef enum {
	INT
}	ElementType;
struct StackRecord;
typedef struct StackRecord* Stack;

int IsEmpty(Stack);
int IsFull(Stack);
Stack CreatStack(int);
void DisposeStack(Stack);
void MakeEmpty(Stack);
void Push(ElementType, Stack);
ElementType Top(Stack);
void Pop(Stack);
ElementType TopAndTop(Stack);
#endif
#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord {
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};

int IsEmpty(Stack K) {
	return K->Array == EmptyTOS;
}
int IsFull(Stack K) {
	return K->Capacity == sizeof(K->Array);
}


Stack CreatStack(int MaxElements) {
	Stack S;
	if (MaxElements < MinStackSize)throw("Stack size is too small");
	S = (Stack)malloc(sizeof(StackRecord));
	if (S == NULL)throw("Out Of Space");
	S->Array = (ElementType *)malloc(sizeof(ElementType));
	if (S->Array == NULL)throw("Out of Space");
	S->Capacity = MaxElements;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack K) {
	if (K != NULL) {
		free(K->Array);
		free(K);
	}
}

void MakeEmpty(Stack K) {
	K->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack K) {
	if (IsFull(K))throw("Full Stack");
	else K->Array[++K->TopOfStack] = X;
}

ElementType Top(Stack K) {
	if (!IsEmpty(K))return K->Array[K->TopOfStack];
	throw("Empty Stack");
	return;
}

void Pop(Stack K) {
	if (IsEmpty(K))throw("Empty Error");
	else K->Capacity--;
	//因为array已经确定 故不用free
}

//给出栈顶元素并且弹出
ElementType TopAndTop(Stack K) {
	if (!IsEmpty(K))return K->Array[K->TopOfStack--];
	throw("Empty Error");
	return;
}