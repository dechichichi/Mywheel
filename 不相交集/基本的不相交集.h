#ifndef _Disjset_
#define NumSets 10

typedef int ElementType;
typedef int DisjDet[NumSets + 1];
typedef int SetType;

void Initilialize(DisjDet S);
void SetUnion(DisjDet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjDet S);
void SetUnionBatter(DisjDet S, SetType Root1, SetType Root2);
SetType FindBatter(ElementType X, DisjDet S);
#endif

void Initilialize(DisjDet S) {
	int i;
	for (i = 1; i<NumSets; i++)S[i] = -1;
}

void SetUnion(DisjDet S, SetType Root1, SetType Root2) {
	S[Root2] = S[Root1];
}

SetType Find(ElementType X, DisjDet S) {
	if (S[X] < 0)return X;
	else return Find(S[X], S);
}
void SetUnionBatter(DisjDet S, SetType Root1, SetType Root2) {
	if (S[Root2] < S[Root1])S[Root1] = Root2;
	else {
		if (S[Root1] == S[Root1])S[Root1]--;//�����ø�����ʾ�������
		//��ʼʱ���Ϊ-1 ��1�Žӵ�2�ź� S[1]=2   S[2]=-2 ˵������2
		S[Root2] = S[Root1];
	}
}

SetType FindBatter(ElementType X, DisjDet S) {
	//·��ѹ��
	if (S[X] <= 0)return X;
	//���Ҹ��ڵ�ʱ�Ѹ��ڵ�����Ϊÿһ���ӽڵ�ĸ��ڵ�  
	//��Ϊ;���Ľڵ���û�������
	else return S[X] = Find(S[X], S);
}