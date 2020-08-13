#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define wordlen 26

struct tnode {
	char word[10];
	int val;
	int height;
	tnode *left, *right;
};

int max(int a, int b) {
	return (a>b)?a:b;
}

int compare(char a[], char b[]) {
	if(strlen(a) < strlen(b)) return -1;
	else if(strlen(a) > strlen(b)) return 1;
	return strcmp(a,b);
}

int getHeight(tnode *curr) {
	if(curr == NULL) return 0;
	return curr->height;
}

int getBalance(tnode *node) {
	if(node == NULL) return 0;
	return getHeight(node->left) - getHeight(node->right);
}

tnode *LeftRotation(tnode *node) {
	struct tnode *S = node->left;
	struct tnode *B = S->right;
	
	S->right = node;
	node->left = B;
	
	node->height = max(getHeight(node->left), getHeight(node->right))+1;
	S->height = max(getHeight(S->left), getHeight(S->right))+1;
	
	return S;
}

tnode *RightRotation(tnode *node) {
	struct tnode *S = node->right;
	struct tnode *B = S->left;
	
	S->left = node;
	node->right = B;
	
	node->height = max(getHeight(node->left), getHeight(node->right))+1;
	S->height = max(getHeight(S->left), getHeight(S->right))+1;
	
	return S;
}

tnode *NewNode(int val, char w[]) {
	struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
	strcpy(node->word, w);
	node->val = val;
	node->height = 1;
	node->left = node->right = NULL;
	return node;	
}

tnode *InsertNode(tnode *node, char w[], int val) {
	if(!node) return NewNode(val, w);
	
	if(compare(w, node->word) < 0) {
		node->left = InsertNode(node->left, w, val);
	}
	else if(compare(w, node->word) > 0) {
		node->right = InsertNode(node->right, w, val);
	}
	else {
		printf("The Word %s : Duplicate Entry !\n", w);
	}
	
	node->height = max(getHeight(node->left), getHeight(node->right))+1;
	int balance = getBalance(node);
	
	if(balance > 1 && getBalance(node->left) > 0) { //LL Rotation
		return LeftRotation(node);
	}
	else if(balance > 1 && getBalance(node->left) < 0) { //LR Rotation
		node->left = RightRotation(node->left);
		return LeftRotation(node);
	}
	else if(balance < -1 && getBalance(node->right) < 0) { //RR Rotation
		return RightRotation(node);
	}
	else if(balance < -1 && getBalance(node->right) > 0) { //RL Rotation
		node->right = LeftRotation(node->right);
		return RightRotation(node);
	}
	
	return node;
}

int searchingValue(tnode *root, char w[]) {
	if(root == NULL) return -1; // ga ada tree
	struct tnode *curr = root;
	while(curr != NULL) {
		if(compare(w, curr->word) < 0) {
			curr = curr->left;
		}
		else if(compare(w, curr->word) > 0) {
			curr = curr->right;
		}
		else {
			return curr->val;
		}
	}
	
	return 0;
}

int main() {
	
	struct tnode *root = NULL;
	int value;
	char word[10] = {};
	int a,b,c,d,e = 0;
	int temp = 0;
	
	// Make a-z
	for(a = 0; a < wordlen; a++) {
		word[0] = a + 'a';
		word[1] = '\0'; // memastikan dia ga ke kolom array yang lain
		temp++;
		root = InsertNode(root, word, temp);
	}
	
	// Make aa-zz
	for(a = 0 ; a < wordlen ; a++) {
		word[0] = a + 'a';
		for(b = a+1 ; b < wordlen ; b++) {
			word[1] = b + 'a';
			word[2] = '\0';
			temp++;
			root = InsertNode(root, word, temp);
		}
	}
	
	// Make aaa-zzz
	for(a = 0 ; a < wordlen ; a++) {
		word[0] = a + 'a';
		for(b = a+1 ; b < wordlen ; b++) {
			word[1] = b + 'a';
			for(c = b+1 ; c < wordlen ; c++) {
				word[2] = c + 'a';
				word[3] = '\0';
				temp++;
				root = InsertNode(root, word, temp);
			}
		}
	}
	
	// Make aaaa-zzzz
	for(a = 0 ; a < wordlen ; a++) {
		word[0] = a + 'a';
		for(b = a+1 ; b < wordlen ; b++) {
			word[1] = b + 'a';
			for(c = b+1 ; c < wordlen ; c++) {
				word[2] = c + 'a';
				for(d = c+1 ; d < wordlen ; d++) {
					word[3] = d + 'a';
					word[4] = '\0';
					temp++;
					root = InsertNode(root, word, temp);
				}
			}
		}
	}
	
	// Make aaaaa-zzzzz
	for(a = 0 ; a < wordlen ; a++) {
		word[0] = a + 'a';
		for(b = a+1 ; b < wordlen ; b++) {
			word[1] = b + 'a';
			for(c = b+1 ; c < wordlen ; c++) {
				word[2] = c + 'a';
				for(d = c+1 ; d < wordlen ; d++) {
					word[3] = d + 'a';
					for(e = d+1 ; e < wordlen ; e++) {
						word[4] = e + 'a';
						word[5] = '\0';
						temp++;
						root = InsertNode(root, word, temp);
					}
				}
			}
		}
	}
	
	char input[10] = {};
	while(scanf("%s", input) == 1) {
		printf("%d\n", searchingValue(root, input));
	}
	
	
	return 0;
}
