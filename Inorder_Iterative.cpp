#include <stdio.h>
#include <stdlib.h>

struct data {
	int val;
	data *left, *right;
};

struct sData {
	data *d;
	sData *next;
};

struct data *newData(int val) {
	struct data *new_Data = (struct data*)malloc(sizeof(struct data));
	new_Data->val = val;
	new_Data->left = new_Data->right = NULL;

	return new_Data;
}

void pushStack(struct sData** head, struct data* node) {
	struct sData *new_Stack = (struct sData*)malloc(sizeof(struct sData));
	
	if(new_Stack == NULL) return;
	new_Stack->d = node;
	new_Stack->next = *head;
	*head = new_Stack;
}

int isEmpty(struct sData *current) {
	return (current == NULL)?1:0;
}

struct data *popStack(struct sData** head) {
	struct data *deletedData;
	struct sData *top;
	
	if(isEmpty(*head)) {
		printf("Overflow!\n");
		return NULL;
	}
	else {
		top = *head;
		deletedData = top->d;
		*head = top->next;
		free(top);
		return deletedData;
	}
}

struct data *pushData(struct data *root, int val) {
	if(root == NULL) return newData(val);
	if(val < root->val) root->left = pushData(root->left, val);
	else if(val > root->val) root->right = pushData(root->right, val);
	else {
		printf("Duplicate Entry\n");
	}
	
	return root;
}

void inOrder_Iterative(struct data *root) {
	if(root == NULL) return;
	struct data *curr = root;
	struct sData *stack = NULL;
	int done = 0;
	
	while(done != 1) {
		if(curr != NULL) { //jika masih ada current dibawahnya
			pushStack(&stack, curr);
			curr = curr->left;
		}
		else { //jika sudah di paling kiri
			if(isEmpty(stack) == 0) { // di cek kalau ga kosong berarti ada nilai di stacknya
				curr = popStack(&stack);
				printf("%d ", curr->val);
				curr = curr->right; //curr ke kanan karena siapa tau ada anak disebelah kanannya
			}
			else { //kalau sudah ga ada stack container lagi, selesai
				done = 1;
			}
		}
	}
}

int main() {
	struct data *root = NULL;
	
	/*
		kita akan membuat root seperti dibawah ini
		
				15
			  /	  \
			11	  20
		   /  \
		 10	  12
		/
	   9
	   
	   apabila kita print secara inorder maka akan menghasilkan:
	   9 10 11 12 15 20
	*/
	root = pushData(root, 15);
	root = pushData(root, 11);
	root = pushData(root, 10);
	root = pushData(root, 12);
	root = pushData(root, 9);
	root = pushData(root, 20);
	
	inOrder_Iterative(root);
	
	return 0;
}
