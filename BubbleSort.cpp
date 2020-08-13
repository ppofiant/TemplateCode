#include <stdio.h>

void swap(int &a , int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *arr, int len) {
	for(int i = len-1; i > 0 ; i--) {
		for(int j = 0 ; j < i ; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main() {
	int arr[1000] = {0};
	int idx, i = 0;
	printf("Ctrl + z to end input number - MAX = 1000\n");
	
	while(scanf("%d", &idx) != EOF) {
		arr[i++] = idx;
	}
	
	bubbleSort(arr, i);
	
	for(int j = 0 ; j < i ; j++) {
		printf("%d ", arr[j]);
	}
	puts("");
	
	return 0;
}
