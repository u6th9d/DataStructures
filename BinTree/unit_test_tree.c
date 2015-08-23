#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

void inc(int* n) {
	*n = *n + 1;
}

void print(int* n) {
	printf("%d ", *n);
}

void tree_test1() {
	BinTree tree = BinTree_Create();
	int buf[] = { 9, 4, 2, 5, 1, 0, 8, 7 };
	for (int i = 0; i < 8; i++) {
		BinTree_Insert(tree, buf[i]);
	}

	BinTree_Delete(tree, 4);
	BinTree_Delete(tree, 7);
	BinTree_Delete(tree, 9);
	BinTree_Delete(tree, 3);

	BinTree_Clear(tree);
	BinTree_Destroy(tree);
}

void tree_test2() {
	BinTree tree = BinTree_Create();
	int buf[] = { 5, 3, 7, 8, 1, 9, 6, 4, 2, 6, 0};
	for (int i = 0; i < sizeof(buf)/sizeof(int); i++) {
		BinTree_Insert(tree, buf[i]);
	}

	BinTree_TravLev(tree, &print); putchar('\n');
	BinTree_TravPost(tree, &inc);
	BinTree_TravIn(tree, &print); putchar('\n');

	int* pint = BinTree_Search(tree, 7);
	printf("%p: %d\n", pint, *pint);

	BinTree_Destroy(tree);
}

int main() {
	tree_test1();
	tree_test2();

	system("pause");
}