#pragma once
#include <cstddef>
#include <malloc.h>
#ifndef _Stakc_h
typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack);
Stack CreatStack(void);
void DisposeStack(Stack);
void MakeEmpty(Stack);
void Push(ElementType, Stack);
ElementType Top(Stack);
void Pop(Stack);
#endif

struct Node {		
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S) {
	return S->Next == NULL;
}

Stack CreatStack(void) {
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)throw("Out Of Space");
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S) {
	if (S == NULL)throw("Must Use CreateStack First");
	else {
		MakeEmpty(S);
		free(S);
	}
}

void MakeEmpty(Stack S) {
	if (S == NULL)throw("Must Use CreateStack First");
	else while (!IsEmpty(S))Pop(S);
}

void Push(ElementType X, Stack S) {
	if (S == NULL) {
		throw("Out of Space");
	}
	PtrToNode TmpCell;
	TmpCell =(PtrToNode) malloc(sizeof(struct Node));
	if (TmpCell == NULL)throw("Out Of Space");
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S) {
	if (!IsEmpty(S))return S->Next->Element;
	throw("Empty Stack");
	return 0;
}

void Pop(Stack S) {
	PtrToNode TmpCell;
	if (!IsEmpty(S)) {
		TmpCell = S->Next;
		S->Next = TmpCell->Next;
		free(TmpCell);
	}
	else throw("Empty Stack");
	return;
}