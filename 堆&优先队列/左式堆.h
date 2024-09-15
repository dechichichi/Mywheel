#pragma once
#include <cstddef>
#include <malloc.h>
#ifndef _LeftHeap_H
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* PriorityQueue;
PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
static PriorityQueue Mergel(PriorityQueue H1, PriorityQueue H2);
#define Insert(X,H)(H=Insertl((X),H));
PriorityQueue Insertl(ElementType X, PriorityQueue H);
PriorityQueue DeleteMinl(PriorityQueue H);
void SwapChildren(PriorityQueue H);
#endif

struct TreeNode {
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2) {
	if (H1 == NULL)return H2;
	if (H2 == NULL)return H1;
	else {
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}
static PriorityQueue Mergel(PriorityQueue H1, PriorityQueue H2) {
	if (H1->Left == NULL)H1->Left = H2;
	else {
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return  H1;
}

PriorityQueue Insertl(ElementType X, PriorityQueue H) {
	PriorityQueue SingleNode;
	SingleNode = malloc(sizeof(struct TreeNode));
	SingleNode->Element = X;
	SingleNode->Npl = 0;
	H = Merge(H, SingleNode);
	return H;
}

PriorityQueue DeleteMinl(PriorityQueue H) {
	PriorityQueue LeftHeap, RightHeap;
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}