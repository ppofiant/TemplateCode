#include <stdio.h>


void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int *arr, int len) {
	for(int j = 0 ; j < len - 1 ; j++) {
		int min = j;
		for(int i = j+1 ; i < len ; i++) {
			if(arr[min] > arr[i]) {
				min = arr[i];
			}
		}
		swap(arr[j], arr[min]);
	}
}

int main() {
	int arr[1000] = {0};
	int idx, i = 0;
	printf("Ctrl + z to end input number -> MAX = 1000\n");
	
	while(scanf("%d", &idx) != EOF) {
		arr[i++] = idx;
	}
	
	selectionSort(arr, i);
	
	for(int j = 0 ; j < i ; j++) {
		printf("%d ", arr[j]);
	}
	puts("");
	
	return 0;
}
