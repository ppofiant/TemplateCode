#include <stdio.h>
#define MAXN 100

int Set[MAXN];

void MakeSet(int n) {
	for(int i = 1; i <= n ; i++) {
		Set[i] = i;
	}
}

int FindParent(int key) {
	if(Set[key] == key) return key;
	return FindParent(Set[key]);
}

void MergeSet(int a, int b) {
	Set[FindParent(a)] = FindParent(b);
}

int isSameSet(int a, int b) {
	return FindParent(a) == FindParent(b);
}

int main() {
	
	MakeSet(10);
	
	MergeSet(1,2);
	MergeSet(2,3);
	MergeSet(5,6);
	MergeSet(6,3);
	
	printf("%d\n", isSameSet(4,5));
	printf("%d\n", isSameSet(6,3));
	printf("%d\n", isSameSet(1,6));
	
	return 0;
}
