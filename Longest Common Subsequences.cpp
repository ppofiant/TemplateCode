#include <stdio.h>
#include <string.h>
#define MAX 999

int max(int a, int b) {
	return (a>b)?a:b;
}

// will return the longest array of lcs
int lcs(char *x, char *y, int a, int b) { // a for len y and b for len x
	int LCS[a+1][b+1];
	for(int i = 0 ; i <= a ; i++) {
		for(int j = 0 ; j <= b ; j++) {
			LCS[i][j] = 0;
		}
	}
	
	for(int i = 0 ; i <= a ; i++) {
		for(int j = 0 ; j <= b ; j++) {
			if(i == 0 || j == 0) { // we set all of index 0 to zero
				LCS[i][j] = 0;
			}
			else if(x[j-1] == y[i-1]) {
				LCS[i][j] = LCS[i-1][j-1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}
	
	puts("");
	printf("Array ke kanan : %s\n", x);
	printf("Array ke bawah : %s\n", y);
	printf("LCS TABLE\n");
	for(int i = 0 ; i <= a ; i++) {
		for(int j = 0 ; j <= b ; j++) {
			printf("%d ", LCS[i][j]);
		}
		puts("");
	}
	puts("");
	
	int i = a;
	int j = b;
	char flag[MAX] = {};
	int temp = 0;
	while(j >= 0 || i >= 0) {
		int currValue = LCS[i][j];
		if(currValue > LCS[i][j-1] && currValue > LCS[i-1][j]) {
			flag[temp] = x[j-1];
			temp++;
			i--; j--;
		}
		else if(currValue == LCS[i-1][j]) {
			i--;
		}
		else {
			j--;
		}
	}
	
	for(int i = temp-1; i >= 0 ; i--) {
		printf("%c", flag[i]);
	}
	puts("");
	
	return LCS[a][b];
}

int main() {
	
	char X[MAX];
	char Y[MAX];
	int len1, len2 = 0;
	printf("ARRAY OF X:\n");
	while(scanf("%c", &X[len1]) != EOF) {
		getchar();
		len1++;
	}
	
	printf("ARRAY OF Y:\n");
	while(scanf("%c", &Y[len2]) != EOF) {
		getchar();
		len2++;
	}
	
	int ans = lcs(X,Y, len2, len1);
	printf("%d\n", ans);
	return 0;
}
