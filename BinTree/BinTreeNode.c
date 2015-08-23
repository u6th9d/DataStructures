/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#include <stdio.h>
#include <malloc.h>
#include "BinTreeNode.h"
#include "Stack.h"
#include "Queue.h"

static int max(int a, int b) {
	return (a > b) ? a : b;
}

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

BinTreeNode BinTreeNode_Create(int item) {
	BinTreeNode node = (BinTreeNode)malloc(sizeof(struct Node));
	if (node != NULL) {
		node->parent = NULL;
		node->lChild = NULL;
		node->rChild = NULL;
		node->data = item;
		node->height = 0;
		node->size = 1;
	}
	return node;
}

int BinTreeNode_Size(BinTreeNode node) {
	if (node == NULL) {
		return 0;
	}
	return node->size;
}

int BinTreeNode_Height(BinTreeNode node) {
	if (node == NULL) {
		return -1;
	}
	return node->height;
}

int BinTreeNode_UpdateSize(BinTreeNode node) {
	if (node == NULL) {
		return -1;
	}
	while (node != NULL) {
		node->size = 1 + BinTreeNode_Size(node->lChild) + BinTreeNode_Size(node->rChild);
		node = node->parent;
	}
	return 0;
}

int BinTreeNode_UpdateHeight(BinTreeNode node) {
	if (node == NULL) {
		return -1;
	}
	while (node != NULL) {
		node->height = 1 + max(BinTreeNode_Height(node->lChild), BinTreeNode_Height(node->rChild));
		node = node->parent;
	}
	return 0;
}

BinTreeNode BinTreeNode_Succ(BinTreeNode node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->rChild != NULL) {
		node = node->rChild;
		while (node->lChild != NULL) {
			node = node->lChild;
		}
	} else {
		while (node->parent != NULL && node->parent->rChild == node) {
			node = node->parent;
		}
		node = node->parent;
	}
	return node;
}

int BinTreeNode_TravPre(BinTreeNode node, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (node == NULL) {
		return -1;
	}
	Stack stack;
	stack_init(&stack, sizeof(BinTreeNode));
	BinTreeNode curr = node;
	stack_push(&stack, &curr);
	while (!stack_empty(&stack)) {
		stack_pop(&stack, &curr);
		if (curr->rChild != NULL) {
			stack_push(&stack, &(curr->rChild));
		}
		if (curr->lChild != NULL) {
			stack_push(&stack, &(curr->lChild));
		}
		func(&curr->data);
	}
	stack_destroy(&stack);
	return 0;
}

int BinTreeNode_TravIn(BinTreeNode node, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (node == NULL) {
		return -1;
	}
	Stack stack;
	stack_init(&stack, sizeof(BinTreeNode));
	BinTreeNode curr = node;
	for ( ; ; ) {
		if (curr != NULL) {
			stack_push(&stack, &curr);
			curr = curr->lChild;
		} else if (!stack_empty(&stack)) {
			stack_pop(&stack, &curr);
			func(&curr->data);
			curr = curr->rChild;
		} else {
			break;
		}
	}
	stack_destroy(&stack);
	return 0;
}

int BinTreeNode_TravPost(BinTreeNode node, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (node == NULL) {
		return -1;
	}
	BinTreeNode_TravPost(node->lChild, func);
	BinTreeNode_TravPost(node->rChild, func);
	func(&node->data);
	return 0;
}

int BinTreeNode_TravLev(BinTreeNode node, Function func) {
	if (func == NULL) {
		return -3;
	}
	if (node == NULL) {
		return -1;
	}
	Queue queue;
	queue_init(&queue, sizeof(BinTreeNode));
	BinTreeNode curr = node;
	queue_enque(&queue, &curr);
	while (!queue_empty(&queue)) {
		queue_deque(&queue, &curr);
		if (curr->lChild != NULL) {
			queue_enque(&queue, &curr->lChild);
		}
		if (curr->rChild != NULL) {
			queue_enque(&queue, &curr->rChild);
		}
		func(&curr->data);
	}
	return 0;
}

int BinTreeNode_Delete(BinTreeNode* proot, int target) {
	if (proot == NULL || *proot == NULL) {
		return -1;
	}
	BinTreeNode* pos = proot;
	while (*pos != NULL) {
		if ((*pos)->data > target) {
			pos = &(*pos)->lChild;
		} else if ((*pos)->data < target) {
			pos = &(*pos)->rChild;
		} else {
			return BinTreeNode_DeleteNode(pos);
		}
	}
	return 0;
}

int BinTreeNode_DeleteNode(BinTreeNode* pnode) {
	BinTreeNode curr = (*pnode);
	BinTreeNode succ = NULL;
	if ((*pnode)->lChild == NULL) {
		succ = *pnode = (*pnode)->rChild;
	} else if ((*pnode)->rChild == NULL) {
		succ = *pnode = (*pnode)->lChild;
	} else {
		curr = BinTreeNode_Succ((*pnode));
		swap(&(*pnode)->data, &curr->data);
		if (curr->parent == (*pnode)) {
			succ = curr->parent->rChild = curr->rChild;
		} else {
			succ = curr->parent->lChild = curr->rChild;
		}
	}
	if (succ != NULL) {
		succ->parent = curr->parent;
	}
	BinTreeNode_UpdateSize(curr->parent);
	BinTreeNode_UpdateHeight(curr->parent);
	free(curr);
	return 0;
}

int* BinTreeNode_Find(BinTreeNode node, int target) {
	if (node == NULL) {
		return NULL;
	}
	if (node->data == target) {
		return &node->data;
	} else if (node->data > target) {
		return BinTreeNode_Find(node->lChild, target);
	} else {
		return BinTreeNode_Find(node->rChild, target);
	}
}

int* BinTreeNode_Insert(BinTreeNode root, int item) {
	if (root == NULL) {
		return NULL;
	}
	BinTreeNode node = root;
	BinTreeNode pos = node;
	while (node != NULL) {
		if (node->data == item) {
			return &node->data;
		} else {
			pos = node;
			if (node->data > item) {
				node = node->lChild;
			} else {
				node = node->rChild;
			}
		}
	}
	BinTreeNode new_node = BinTreeNode_Create(item);
	if (pos->data > item) {
		BinTreeNode_InsertAsLC(pos, new_node);
	} else {
		BinTreeNode_InsertAsRC(pos, new_node);
	}
	return &new_node->data;
}

int BinTreeNode_InsertAsLC(BinTreeNode node, BinTreeNode item) {
	if (node == NULL) {
		return -2;
	}
	if (item == NULL) {
		return -1;
	}
	node->lChild = item;
	item->parent = node;
	item->lChild = NULL;
	item->rChild = NULL;
	item->height = 0;
	item->size = 1;

	BinTreeNode_UpdateHeight(node);
	BinTreeNode_UpdateSize(node);
	return 0;
}

int BinTreeNode_InsertAsRC(BinTreeNode node, BinTreeNode item) {
	if (node == NULL) {
		return -2;
	}
	if (item == NULL) {
		return -1;
	}
	node->rChild = item;
	item->parent = node;
	item->lChild = NULL;
	item->rChild = NULL;
	item->height = 0;
	item->size = 1;

	BinTreeNode_UpdateHeight(node);
	BinTreeNode_UpdateSize(node);
	return 0;
}

int BinTreeNode_Destroy(BinTreeNode node) {
	if (node == NULL) {
		return -1;
	}
	BinTreeNode_Destroy(node->lChild);
	BinTreeNode_Destroy(node->rChild);
	free(node);
	return 0;
}
