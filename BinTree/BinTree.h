/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "BinTreeNode.h"

typedef struct Tree* BinTree;

struct Tree {
	BinTreeNode root;
};

int BinTree_Size(BinTree tree);

int BinTree_Height(BinTree tree);

BinTree BinTree_Create();

int* BinTree_Insert(BinTree tree, int item);

int* BinTree_Search(BinTree tree, int target);

int BinTree_TravPre(BinTree tree, Function func);

int BinTree_TravIn(BinTree tree, Function func);

int BinTree_TravPost(BinTree tree, Function func);

int BinTree_TravLev(BinTree tree, Function func);

int BinTree_Delete(BinTree tree, int target);

int BinTree_Clear(BinTree tree);

int BinTree_Destroy(BinTree tree);

#endif
