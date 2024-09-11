#pragma once
#include<stdio.h>
#include <malloc.h>
typedef int ListItem;
typedef ListItem* addr;
#define eq(A,B)(A==B)

void ItemShow(ListItem x) {
	printf("%d \n", x);
}

typedef struct alist* List;
typedef struct alist {
	int n;//表长
	int curr;//当前位置
	int maxsize;//数组上界
	ListItem *table;//记录表中的数组
};

//下面是List的接口函数
List ListInit(int);//表结构初始化
int ListEmpty(List);//测试表是否为空
int ListLength(List);//表长度
ListItem ListRetrieve(int k, List L);//返回表L位置k处的元素
int ListLocate(ListItem x, List L);//元素x在表L中的位置
void ListInsert(int k, ListItem x, List L);//插入元素
ListItem ListDelete(int k, List L);//删除表L中k位置元素
void PrintList(List L);//按位置次序输出表L中元素

//接口函数的实现
//初始化
List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->table = (ListItem*)malloc(size * sizeof(ListItem));//元素  table[0]-table[1]-table[2]-table[3]......
	L->maxsize = size;
	L->n = 0;
	return L;
}

//检查表是否为空
int ListEmpty(List L) {
	return L->n == 0;
}

//查询表长度
int ListLength(List L) {
	return L->n;
}

//返回元素位置
int ListLocate(ListItem x, List L) {
	for (int i = 0; i < L->n; i++) {
		if (L->table[i] == x)return ++i;
		return 0;
	}
}

//返回指定位置的元素
ListItem ListRetrieve(int k, List L) {
	if (k<1 || k>L->n)return 0;
	return L->table[k - 1];
}

//插入元素
void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n)return;
	for (int i = L->n - 1; i >= k; i--)L->table[i + 1] = L->table[i];
	L->table[k] = x;
	L->n++;
}

//删除表L中k位置元素
ListItem ListDelete(int k, List L) {
	if (k<1 || k>L->n)return;
	ListItem x = L->table[k - 1];
	for (int i = k; i < L->n; i++)L->table[i - 1] = L->table[i];
	L->n--;
	return x;
}

//按位置次序输出表L中元素
void PrintList(List L) {
	if (L->n == 0)return;
	for (int i = 0; i < L->n; i++)ItemShow(L->table[i]);
}