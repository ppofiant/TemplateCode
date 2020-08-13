#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void createLPS(int *LPS, char needle[]) {
	int len = strlen(needle);
	int i = 0;
	LPS[0] = 0;
	int j = 1;
	
	while(j < len) {
		if(needle[i] == needle[j]) {
			i++;
			LPS[j] = i;
			j++;
		}
		else {
			if(i!=0) {
				i = LPS[i-1];
			}
			else {
				LPS[j] = 0;
				j++;
			}
		}
	}
}

void PrintLPS(int *LPS, int len) {
	
	printf("\nLPS TABLE\n");
	printf("=========\n");
	
	for(int i = 0 ; i < len ; i++) {
		if(len - 1 == i) printf("%d  --> INDEX\n", i);
		else {
			printf("%d | ", i);
		}
	}
	for(int i = 0; i < len ; i++) {
		if(len - 1 == i) printf("%d\n", LPS[i]);
		else {
			printf("%d   ", LPS[i]);
		}
	}
}


int main() {
	
	char needle[50] = {};
	
	while(gets(needle)) {
		if(needle[0] == '\0') break;
		else {
			int len = strlen(needle);
			int LPS[len];
			
			// Create LPS
			createLPS(LPS, needle);
			//Print
			PrintLPS(LPS, len);
		}
	}
	
	return 0;
}
