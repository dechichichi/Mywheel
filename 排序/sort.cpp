#include<iostream>
using namespace std;

//插入排序
void InsertionSort(int A[],int N ) {
	int j, p;
	for (p = 1; p < N;p++) {
		int tmp = A[p];
		for (j = p; j > 0 && A[j - 1] > tmp; j--)A[j] =A[j-1];//不断回退 回退的同时移动数组
		A[j] = tmp;
	}
}

//希尔排序
void ShellSort(int A[], int N) {
	int i, j, Increment;
	int tmp;
	for (Increment = N >> 1; Increment > 0; Increment >>= 1) {
		for (int i = Increment; i < N; i++) {
			tmp = A[i];
			for (j = i; j > Increment; j -= Increment)
				if (tmp < A[j - Increment])A[j] = A[j - Increment];
				else break;
			A[j] = tmp;
		}
	}
}

//堆排序
#define LeftChild(i)(2*(i)+1)//由于这个 从N/2开始就可以得到整个数组

void PercDown(int A[], int i, int N) {
	int Child;
	int Tmp;
	for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])Child++;
		if (Tmp < A[Child])A[i] = A[Child];
		else break;
	}
	A[i] = Tmp;
}

void HeapSort(int A[],int N) {
	int i;
	for (int i = N/2; i >= 0; i--)PercDown(A, i, N);
	for (int i = N - 1; i > 0; i--) {
		swap(A[0], A[i]);
		PercDown(A, 0, i);
	}
}

//归并排序
void Merge(int A[], int tmparray[], int lpos, int rpos, int rightend) {
	int t = 0;
	int i = lpos, j = rpos;
	for (i = lpos, j = rpos; i != rpos && j != rightend;)
		if (A[i] <= A[j]) tmparray[t++] = A[i++];
		else tmparray[t++] = A[j++];
	while (i != rpos)tmparray[t++] = A[i++];
	while (j != rpos)tmparray[t++] = A[j++];
}

void Msort(int A[], int tmparray[], int left, int right) {
	int center;
	if (left < right) {
		center = left + (right - left) >> 1;
		Msort(A, tmparray, left, center);
		Msort(A, tmparray, center + 1, right);
	}
}


void MergeSort(int A[], int N) {
	int* tmparry = (int*)malloc(N * sizeof(int));
	Msort(A, tmparry, 0, N - 1);
	free(tmparry);
}

//快速排序


int Median3(int A[], int left, int right) {
	int center = (left + right) >> 1;
	if (A[left] > A[center])swap(A[left], A[center]);
	if (A[left] > A[right])swap(A[left], A[right]);
	if (A[center] > A[right])swap(A[center], A[right]);
	swap(A[center], A[right - 1]);
	return A[right - 1];
}

void qsort(int A[], int left, int right) {
	int i, j;
	int pivot;
	if (left <= right) {
		pivot = Median3(A, left, right);
		i = left, j = right - 1;
		while (true) {
			while (A[++i] < pivot);
			while (A[--j] > pivot);
			if (i < j)swap(A[i], A[j]);
			else break;
		}
		swap(A[i], A[right - 1]);
		qsort(A, left, i - 1);
		qsort(A, i + 1, right);
	}
	else InsertionSort(A + left, right - left + 1);
}

void quicksort(int A[], int N) {
	qsort(A, 0, N - 1);
}