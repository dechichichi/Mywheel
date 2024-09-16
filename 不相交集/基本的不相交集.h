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
		if (S[Root1] == S[Root1])S[Root1]--;//我们用负数表示树的深度
		//初始时深度为-1 把1号接到2号后 S[1]=2   S[2]=-2 说明树深2
		S[Root2] = S[Root1];
	}
}

SetType FindBatter(ElementType X, DisjDet S) {
	//路径压缩
	if (S[X] <= 0)return X;
	//在找根节点时把根节点设置为每一个子节点的根节点  
	//因为途径的节点是没有意义的
	else return S[X] = Find(S[X], S);
}