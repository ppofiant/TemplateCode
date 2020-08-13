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

void KMP_Search(int LPS[], char needle[], char stack[]) {
	int len_stack = strlen(stack);
	int len_needle = strlen(needle);
	int i, j = 0;
	
	int idx;
	int failure;
	int slide;
	int startidx = 0;
	while( i < len_stack) {
		printf("\nStart at Index : %d\n", i);
		j = startidx;
		int same = 0;
		while( j < len_needle ) {
			printf("Stack : %c VS %c Needle\n", stack[j+i], needle[j]);
			if(needle[j] == stack[j+i]) {
				if(same == len_needle-1) {
					printf("Founded at index : %d\n\n", i);
					return;
				}
				j++;
				same++;
			}
			else {
				if(j == 0) {
					i++;
					startidx = 0;
					printf("\n=======\n");
					printf("SLIDE %d\n", 1);
					printf("========\n");
					break;
				}
				else {
					idx = j;
					failure = LPS[idx - 1];
					slide = idx - failure;
					i += slide;
					startidx = failure;
					printf("\n=======\n");
					printf("Failed at Index %d\n", j);
					printf("Failure %d\n", failure);
					printf("Slide %d\n", slide);
					printf("After Slide compare from idx %d\n", startidx);
					printf("========\n");
					break;
				}
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
			
			createLPS(LPS, needle); // Create Prefix Table
			PrintLPS(LPS, len); // Print Prefix Table
			
			char stack[100] = {};
			printf("\nInput Stack : [ctrl+z to end searching]\n");
			gets(stack);
			stack[strlen(stack)] = '\0';	
			KMP_Search(LPS, needle, stack);
		}
	}
	
	return 0;
}
