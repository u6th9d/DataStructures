/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#ifndef _BINTREENODE_H_
#define _BINTREENODE_H_

typedef struct Node* BinTreeNode;

struct Node {
	BinTreeNode parent;
	BinTreeNode lChild;
	BinTreeNode rChild;
	int data;
	int height;
	int size;
};

typedef void(*Function)(int*);

BinTreeNode BinTreeNode_Create(int item);

int BinTreeNode_Size(BinTreeNode node);

int BinTreeNode_Height(BinTreeNode node);

int BinTreeNode_UpdateSize(BinTreeNode node);

int BinTreeNode_UpdateHeight(BinTreeNode node);

//BinTreeNode BinTreeNode_Pred(BinTreeNode node);

BinTreeNode BinTreeNode_Succ(BinTreeNode node);

int* BinTreeNode_Find(BinTreeNode node, int target);

int* BinTreeNode_Insert(BinTreeNode root, int item);

// traversal
int BinTreeNode_TravPre(BinTreeNode node, Function func);

int BinTreeNode_TravIn(BinTreeNode node, Function func);

int BinTreeNode_TravPost(BinTreeNode node, Function func);

int BinTreeNode_TravLev(BinTreeNode node, Function func);

int BinTreeNode_Delete(BinTreeNode* proot, int target);

int BinTreeNode_DeleteNode(BinTreeNode* pnode);

int BinTreeNode_InsertAsLC(BinTreeNode node, BinTreeNode item);

int BinTreeNode_InsertAsRC(BinTreeNode node, BinTreeNode item);

int BinTreeNode_Destroy(BinTreeNode node);

#endif
