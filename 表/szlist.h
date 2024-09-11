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
	int n;//��
	int curr;//��ǰλ��
	int maxsize;//�����Ͻ�
	ListItem *table;//��¼���е�����
};

//������List�Ľӿں���
List ListInit(int);//��ṹ��ʼ��
int ListEmpty(List);//���Ա��Ƿ�Ϊ��
int ListLength(List);//����
ListItem ListRetrieve(int k, List L);//���ر�Lλ��k����Ԫ��
int ListLocate(ListItem x, List L);//Ԫ��x�ڱ�L�е�λ��
void ListInsert(int k, ListItem x, List L);//����Ԫ��
ListItem ListDelete(int k, List L);//ɾ����L��kλ��Ԫ��
void PrintList(List L);//��λ�ô��������L��Ԫ��

//�ӿں�����ʵ��
//��ʼ��
List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->table = (ListItem*)malloc(size * sizeof(ListItem));//Ԫ��  table[0]-table[1]-table[2]-table[3]......
	L->maxsize = size;
	L->n = 0;
	return L;
}

//�����Ƿ�Ϊ��
int ListEmpty(List L) {
	return L->n == 0;
}

//��ѯ����
int ListLength(List L) {
	return L->n;
}

//����Ԫ��λ��
int ListLocate(ListItem x, List L) {
	for (int i = 0; i < L->n; i++) {
		if (L->table[i] == x)return ++i;
		return 0;
	}
}

//����ָ��λ�õ�Ԫ��
ListItem ListRetrieve(int k, List L) {
	if (k<1 || k>L->n)return 0;
	return L->table[k - 1];
}

//����Ԫ��
void ListInsert(int k, ListItem x, List L) {
	if (k<0 || k>L->n)return;
	for (int i = L->n - 1; i >= k; i--)L->table[i + 1] = L->table[i];
	L->table[k] = x;
	L->n++;
}

//ɾ����L��kλ��Ԫ��
ListItem ListDelete(int k, List L) {
	if (k<1 || k>L->n)return;
	ListItem x = L->table[k - 1];
	for (int i = k; i < L->n; i++)L->table[i - 1] = L->table[i];
	L->n--;
	return x;
}

//��λ�ô��������L��Ԫ��
void PrintList(List L) {
	if (L->n == 0)return;
	for (int i = 0; i < L->n; i++)ItemShow(L->table[i]);
}