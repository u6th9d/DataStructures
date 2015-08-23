/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#include <stdlib.h>
#include "BinTree.h"

int BinTree_Size(BinTree tree) {
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return 0;
	}
	return BinTreeNode_Size(tree->root);
}

int BinTree_Height(BinTree tree) {
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_Height(tree->root);
}

BinTree BinTree_Create() {
	BinTree tree = (BinTree)malloc(sizeof(struct Tree));
	if (tree != NULL) {
		tree->root = NULL;
	}
	return tree;
}

int* BinTree_Insert(BinTree tree, int item) {
	if (tree == NULL) {
		return NULL;
	}
	if (tree->root == NULL) {
		tree->root = BinTreeNode_Create(item);
		return &(tree->root->data);
	}
	return BinTreeNode_Insert(tree->root, item);
}

int* BinTree_Search(BinTree tree, int target) {
	if (tree == NULL || tree->root == NULL) {
		return NULL;
	}
	return BinTreeNode_Find(tree->root, target);
}

int BinTree_TravPre(BinTree tree, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_TravPre(tree->root, func);
}

int BinTree_TravIn(BinTree tree, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_TravIn(tree->root, func);
}

int BinTree_TravPost(BinTree tree, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_TravPost(tree->root, func);
}

int BinTree_TravLev(BinTree tree, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_TravLev(tree->root, func);
}

int BinTree_Delete(BinTree tree, int target) {
	if (tree == NULL) {
		return -2;
	}
	if (tree->root == NULL) {
		return -1;
	}
	return BinTreeNode_Delete(&(tree->root), target);
}

int BinTree_Clear(BinTree tree) {
	if (tree == NULL) {
		return -2;
	}
	BinTreeNode node = tree->root;
	tree->root = NULL;
	return BinTreeNode_Destroy(node);
}

int BinTree_Destroy(BinTree tree) {
	if (tree == NULL) {
		return -2;
	}
	BinTreeNode root = tree->root;
	free(tree);
	return BinTreeNode_Destroy(root);
}
