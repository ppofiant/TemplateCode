#include <stdio.h>
#define MAX 999

void bubbleFlag(int len, int *arr) {
	int sorted = 0;
	for(int i = len - 1; i >= 0 ; i--) {
		for(int j = 0 ; j < i ; j++) {
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				sorted = 1;
			}
		}
		if(sorted == 0) break;
	}
}

int main() {
	int arr[MAX] = {0};
	int len = 0;
	while(scanf("%d", &arr[len]) != EOF) {
		len++; // get len
	}
	
	bubbleFlag(len, arr);
	
	for(int i = 0 ; i < len ; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
	
	return 0;
}
