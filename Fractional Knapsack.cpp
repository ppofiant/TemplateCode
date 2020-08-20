#include <stdio.h>
#define MAX 999

struct data {
	int weight;
	float value;
};

struct data arrTemp[MAX] = {0};

void mergeSort(int left, int right, data *arr) {
	if(left == right) return;
	int mid = (left + right)/2;
	
	mergeSort(left, mid, arr);
	mergeSort(mid+1, right, arr);
	
	int startLeft = left;
	int startRight = mid+1;
	int toMid = mid;
	int toRight = right;
	
	int temp = left;
	while(startLeft <= toMid && startRight <= toRight) {
		double valuePerWeightLeft = (arr[startLeft].value / arr[startLeft].weight);
		double valuePerWeightRight = (arr[startRight].value / arr[startRight].weight);
		if( valuePerWeightLeft > valuePerWeightRight ) {
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
	
	for(int i = left; i < temp ; i++) {
		arr[i] = arrTemp[i];
	}
}

// Using merge-sort
void *sort(int len, data *arr) {
	int left = 0;
	int right = len - 1;
	mergeSort(left,right,arr);
}

void printData(int len, data *arr) {
	printf("Sorted array\n");
	for(int i = 0; i < len ; i++) {
		printf("%d %.0f\n", arr[i].weight, arr[i].value);
	}
}

void fractionalKnapsack(int len, data* arr, int capacity) {
	int currWeight = 0;
	double finalValue = 0.0;
	for(int i = 0 ; i < len ; i++) {
		if(currWeight + arr[i].weight <= capacity) { //kalau muat
			currWeight += arr[i].weight;
			finalValue += arr[i].value;
		}
		else {
			int sisa = capacity - currWeight;
			finalValue += arr[i].value* ((double) sisa / arr[i].weight); // must input (double) because we know that int can't contain the float things
			break;
		}
	}
	
	printf("Maximum Value in %d capacity is : %.0f\n", capacity, finalValue);
}

int main() {	
	struct data arr[MAX] = {0};
	int len = 0;
	printf("please input based on the template below:\n");
	printf("[weight] [value]\n");
	while(scanf("%d %f", &arr[len].weight, &arr[len].value) != EOF) {
		len++;
	}
	
	int capacity;
	printf("Input capacity to calculate the maximum [numeric]: ");
	scanf("%d", &capacity);
	//sorting first based on value;
	sort(len, arr);
	//check if the data is sorted or not
    //printData(len, arr);
	
	//if sorted well go to the fractional knapsack
	fractionalKnapsack(len, arr, capacity);
	
	return 0;
}
