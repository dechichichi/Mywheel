#pragma once
#pragma once
#include <cstddef>
#include <malloc.h>

#ifndef _SplayTree_H

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree);
Position Find(ElementType, AvlTree);
Position FindMin(AvlTree);
Position FindMax(AvlTree);
AvlTree Insert(ElementType, AvlTree);
AvlTree Delete(ElementType, AvlTree);
ElementType Retrieve(Position);
AvlTree SingleRotateWithLeft(AvlTree);
AvlTree SingleRotateWithRight(AvlTree);
AvlTree DoubleRotateWithLeft(AvlTree);
AvlTree DoubleRotateWithRight(AvlTree);
#endif
struct AvlNode {
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

ElementType max(ElementType X1, ElementType X2) {
	return X1 > X2 ? X1 : X2;
}

static int Height(Position P) {
	if (P == NULL)return -1;
	else return P->Height;
}

AvlTree Insert(ElementType X, AvlTree T) {
	if (T == NULL) {
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)throw("out of space");
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		//´¦Àí
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)T = SingleRotateWithLeft(T);
			else T = DoubleRotateWithLeft(T);

	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (X < T->Right->Element)T = SingleRotateWithRight(T);
			else T = DoubleRotateWithRight(T);
	}
}
AvlTree SingleRotateWithLeft(AvlTree K2) {
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;
}
AvlTree SingleRotateWithRight(AvlTree K2) {
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	return K1;
}
AvlTree DoubleRotateWithLeft(AvlTree K3) {
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}
AvlTree DoubleRotateWithRight(AvlTree K3) {
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}