#pragma once
#include<stdio.h>
#include <malloc.h>



typedef enum {
	INT,
	CHAR,
	FOLOAT
}ListItem;

struct node;
typedef struct node* link;
typedef struct node {
	ListItem element;
	link next;
}Node;

link NewNode() {
	return(link)malloc(sizeof(Node));
}

typedef struct llist *List;
typedef struct llist {
	link first,
		curr,
		last;
}Llist;

//下面是List的接口函数
List ListInit();
int ListEmpty(List L);
int ListLength(List L);
ListItem ListRetrieve(int k, List L);
int ListLocate(ListItem, List);
void ListInsert(int, ListItem, List);
ListItem ListDelte(int, List);
void PrintList(List L);
void ItemShow(ListItem x) {
	printf("%d \n", x);
}

List ListInit() {
	List L = (List)malloc(sizeof * L);
	L->first = 0;
	return L;
}

int ListEmpty(List L) {
	return L->first == 0;
}

int ListLength(List L) {
	int len = 0;
	link p = L->first;
	while (p) {
		p = p->next;
		len++;
	}
	return len;
}

ListItem ListRetrieve(int k, List L) {
	if (k < 1)return;
	link p = L->first;
	int i = k-1;
	while (i-- && p) {
		p = p->next;
	}
	return p->element;
}
int ListLocate(ListItem x, List L) {
	int i = 1;
	link p = L->first;
	while (p && p->element != x) {
		p = p->next;
		i++;
	}
	return p ? i: 0;
}

void ListInsert(int k, ListItem x, List L) {
	if (k < 0)return;
	link p = L->first;
	for (int i = 1; i < k && p; i++)p = p->next;
	link y = NewNode();
	y->element = x;
	if (k) {
		y->next = p->next; p->next = y;
	}
	else {
		y->next = L->first; L->first = y;
	}
}

ListItem ListDelte(int k, List L) {
	if (k < 1 || !L->first)return ;
	link p = L->first;
	if (k == 1)L->first = p->next;
	else {
		link q = L->first;
		for (int i = 1; i < k - 1 && q; i++)q = q->next;
		p = q->next;
		q->next = p->next;
	}
	ListItem x=p->element;
	free(p);
	return x;
}

void PrintList(List L) {
	for (link p = L->first; p; p = p->next)ItemShow(p->element);
}
