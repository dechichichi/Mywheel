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

//接口函数
int ListEmpty(List);
int ListLength(List);




//函数实现
int ListEmpty(List L) {
	return L->n == 0;
}

int ListLength(List L) {
	return L->n;
}