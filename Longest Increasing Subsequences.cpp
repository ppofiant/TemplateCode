#include <stdio.h>
#define MAX 999

int lis(int n, int* arr) {
	//define arr lis
	int lis[n] = {0};
	
	//assign lis nya menjadi 1
	for(int i = 0; i < n ; i++) {
		lis[i] = 1;
	}
	
	// kemudian dimulai looping
	// for i = 1 to i = len-1
	// for j = 0 to j = i - 1
	// jika arr[i] > arr[j], maka
	// cek kalau lis[i] > lis[j] + 1, maka lis[i] = lis[j]+1
	for(int i = 1 ; i < n ; i++) {
		for(int j = 0 ; j < i ; j++) {
			if(arr[i] > arr[j]) {
				if(lis[i] < lis[j]+1) {
					lis[i] = lis[j]+1;
				}
			}
		}
	}
	
	// mulai pada tahap mencari max lis
	int max = -1;
	for(int i = 0 ; i < n ; i++) {
		if(max < lis[i]) {
			max = lis[i];
		}
	}
	
	printf("LIS : ");
	for(int i = 0 ; i < n ; i++) {
		printf("%d ", lis[i]);
	}
	puts("");
	
	return max;
}

int main() {
	
	//define an array
	int arr[MAX] = {0};
	int len = 0;
	while(scanf("%d", &arr[len]) != EOF) {
		len++;
	}
	
	//kemudian, mulai ke lis nya
	int longest = lis(len, arr);
	printf("The longest increasing subsequences are: %d\n", longest);
	
	return 0;
}
