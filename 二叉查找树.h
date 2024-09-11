#pragma once
#include <cstddef>
#include<stdlib.h>
#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef  struct TreeNode* SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
#endif

struct TreeNode {
	int tag = 1;
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X,SearchTree T) {
	if (T == NULL)return NULL;
	if (X == T->Element&&T->tag==1)return T;
	if (X < T->Element)return Find(X, T->Left);
	if (X > T->Element)return Find(X, T->Right);
}

Position FindMin(SearchTree T) {
	if (T == NULL)return NULL;
	else if (T->Left == NULL&&T->tag==1)return T;
	else return FindMin(T->Left);
}

Position FindMax(SearchTree T) {
	//这里为了展示第二种方法 不使用递归实现
	if (T != NULL) {
		while (T->Right != NULL)T = T->Right;
	}
	return T;
}

SearchTree Insert(ElementType X, SearchTree T) {
	if (T == NULL) {
		T = (SearchTree)malloc(sizeof(TreeNode));
		if (T == NULL)throw("out of space");
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)Insert(X, T->Left);
	else if (X > T->Element)Insert(X, T->Right);
	return T;
}

SearchTree Delete(ElementType X, SearchTree T) {
	SearchTree T1 = Find(X, T);
	if (T1 != NULL)T1->tag = 0;
	return T;
}