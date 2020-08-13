#include <stdio.h>
#define MAXVertex 100

int Set[MAXVertex];

struct Vertex {
	int a, b;
	int cost;
};

struct Vertex arr[MAXVertex];

void MakeNode(int a) {
	for(int i = 0; i < a ; i++) {
		Set[i] = i;
	}
}

int FindParent(int val) {
	if(Set[val] == val) return val;
	return FindParent(Set[val]);
}

int IsSameSet(int a , int b) {
	return FindParent(a) == FindParent(b);
}

void MergeSet(int a, int b) {
	Set[FindParent(a)] = FindParent(b);
}


int main() {
	
	int V, E;
	printf("Masukkan Vertex yang ingin di tambahkan : ");
	scanf("%d", &V);
	
	//Make Set sebanyak V kali
	MakeNode(V);
	
	printf("Masukkan jumlah Edge yang ingin di tambahkan : ");
	scanf("%d", &E);
	
	for(int i = 0 ; i < E ; i++) {
		printf("Input set Which is you want to connect with [int, int]\n");
		scanf("%d %d", &arr[i].a, &arr[i].b);
		printf("How Much it cost?\n");
		scanf("%d", &arr[i].cost);
	}
	
	//Bubble Sort -optional method
	for(int i = E-1; i > 0 ; i--) {
		for(int j = 0 ; j < i ; j++) {
			if(arr[j].cost > arr[j+1].cost) {
				struct Vertex temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	//Starting Using MST
	int MinimumSpanningTree = 0;
	for(int i = 0 ; i < E; i++) {
		if(IsSameSet(arr[i].a, arr[i].b)) {
			continue; // Karena udah 1 set makanya ga ada penambahan
		}
		else {
			MergeSet(arr[i].a, arr[i].b);
			MinimumSpanningTree += arr[i].cost;
		}
	}
	
	printf("Total Minimum Spanning Tree that we create is : %d\n", MinimumSpanningTree);
	
	return 0;
}
