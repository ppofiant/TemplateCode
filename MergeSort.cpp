#include <stdio.h>
#define MAX 999

int arrTemp[MAX] = {0};

void mergeSort(int left, int right, int *arr) {
	if(left == right) return;
	int mid = (left + right)/2;
	
	mergeSort(left, mid, arr);
	mergeSort(mid+1, right, arr);
	
	int startLeft = left;
	int startRight = mid + 1;
	int toMid = mid;
	int toRight = right;
	
	int temp = left; //mulai dari paling kiri which is left
	
	while(startLeft <= toMid && startRight <= toRight) {
		if(arr[startLeft] < arr[startRight]) {
			arrTemp[temp] = arr[startLeft];
			startLeft++;
		}
		else {
			arrTemp[temp] = arr[startRight];
			startRight++;
		}
		temp++;
	}
	
	while(startLeft <= toMid) {
		arrTemp[temp] = arr[startLeft];
		startLeft++; temp++;
	}
	while(startRight <= toRight) {
		arrTemp[temp] = arr[startRight];
		startRight++; temp++;
	}
	
	for(int i = 0; i < temp ; i++) {
		arr[i] = arrTemp[i];
	}
}

int main() {
	int arr[MAX] = {0};
	int len = 0;
	while(scanf("%d", &arr[len]) != EOF) {
		len++; // get len
	}
	
	int left = 0;
	int right = len;
	
	//Starting merge
	mergeSort(left, right, arr);
	
	for(int i = 0 ; i < len ; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
	
	return 0;
}
