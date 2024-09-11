#pragma once
#include<stdio.h>
#include <malloc.h>
typedef enum {
	INT,
	FLOAT
}ListItem;
typedef ListItem* addr;
typedef struct indlist* List;
typedef struct indlist {
	int n, cur;
	int maxsize;
	addr* table;
};

addr NewNode(){
	return (addr)malloc(sizeof(addr));
}

List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->n = 0;
	L->maxsize = size;
	L->table = (addr*)malloc(sizeof(addr) * size);
	return L;
}

//�ӿں���
int ListEmpty(List);
int ListLength(List);




//����ʵ��
int ListEmpty(List L) {
	return L->n == 0;
}

int ListLength(List L) {
	return L->n;
}