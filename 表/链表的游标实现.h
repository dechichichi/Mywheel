#pragma once
#include <stdlib.h>
#ifndef _Cursor_H
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Postion;

void InitCursorSpace(int N);
static Postion CursorAlloc();
static void CursorFree(Postion P);
int IsEmpty(const List L);
int IsLast(const Postion P, const List L);
Postion Find(ElementType X, const List L);
void Delete(List L, Postion P);
Postion FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Postion P);
List MakeEmpty(List L);
void DeleteList(List L);
Postion Header(const List L);
Postion First(const List L);
Postion Advance(const Postion P);
ElementType Retireve(const Postion P);
#endif

struct Node {
	ElementType Element;
	Postion Next;
};

//游标实现的核心
struct Node* CursorSpace;

void InitCursorSpace(int N) {
	CursorSpace = (Node*)malloc(sizeof(Node) * N);
	for (int i = 0; i < N - 1; i++) {
		CursorSpace[i].Next = i + 1;
	}
}

static Postion CursorAlloc() {
	Postion P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return P;
}

static void CursorFree(Postion P) {
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}



int IsEmpty(const List L) {
	return CursorSpace[L].Next == 0;
}

int IsLast(const Postion P, const List L) {
	return CursorSpace[P].Next == 0;
}


Postion Find(ElementType X, const List L) {
	Postion P;
	P = CursorSpace[L].Next;
	while (P && CursorSpace[P].Element != X)P = CursorSpace[P].Next;
	return P;
}

void Delete(List L, Postion P) {
	Postion Tmp;
	Tmp = CursorSpace[L].Next;
	while (Tmp && CursorSpace[Tmp].Next != P)Tmp = CursorSpace[Tmp].Next;
	CursorSpace[Tmp].Next = CursorSpace[P].Next;
	CursorFree(P);
}

Postion FindPrevious(ElementType X, List L) {

}

void Insert(ElementType X, List L, Postion P) {
	Postion TmpCell;
	TmpCell = CursorAlloc();
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}