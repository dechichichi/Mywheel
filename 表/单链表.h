#pragma once
#include <cstddef>
#ifndef _List_H
#include<stdlib.h>
//声明区域
struct Node;
typedef struct Node* PtrToNode;
//name Node* PtrToNode
typedef PtrToNode List;
typedef PtrToNode Position;
typedef enum {
	INT,
	FLOAT,
	DOUBLE,
	CHAR
} ElementType;
struct Node
{
	ElementType Element;
	Position Next;
};


//函数声明区
List ListInit();
List MakeEmpty(List);
int IsEmpty(List);
int IsLast(Position, List);
Position Find(ElementType, List);
void Delete(ElementType, List);
Position FindPrevious(ElementType, List);
void Insert(ElementType, List, Position);
void DeleteList(List);
Position Header(List);
Position First(List);
Position Advance(Position P);
ElementType Retrieve(Position P);
#endif			



//函数实现区
List ListInit() {
	List L = (List)malloc(sizeof * L);
	return L;
}

List MakeEmpty(List &L) {
	Position P = L;
	while (P->Next!=NULL&&P!=NULL) {
		Position TmpCell = P->Next;
		P = NULL;
		P = TmpCell;
	}
	return L;
}


int IsEmpty(List L) {
	return L->Next == NULL;
}

int IsLast(Position P, List L) {
	return P->Next == NULL;
}

Position Find(ElementType X, List L) {
	Position P;
	P = L->Next;
	while ((P->Element != X) && (P != NULL))P = P->Next;
	return P;
}

void Delete(ElementType X, List &L) {
	Position P, TempCell;
	P = FindPrevious(X, L);
	if (P!=NULL&&P->Next!=NULL) {
		TempCell = P->Next;
		P->Next = TempCell->Next;
		free(TempCell);
	}
}

Position FindPrevious(ElementType X, List L) {
	Position P;
	P = L;
	while(P->Next->Element != X && P->Next != NULL)P = P->Next;
	return P;
}

void Insert(ElementType X, List L, Position &P) {
	Position TmpCell;
	TmpCell =(Position) malloc(sizeof(struct Node));
	if (TmpCell == NULL)throw("Out of Space!!");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List &L) {
	Position P, TmpCell;
	P = L->Next;
	L->Next = NULL;
	while (P!=NULL) {
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
	return;
}

Position Header(List L) {
	return L;
}