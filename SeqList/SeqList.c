#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

typedef struct _tag_SeqListNode {
	int capacity;
	int length;
	SeqListNode* node;
}*TSeqList;

SeqList SeqListCreate(int capacity) {	//O(1)
	TSeqList ret = NULL;
	if (capacity >= 0) {
		ret = (TSeqList)malloc(sizeof(struct _tag_SeqListNode) + capacity * sizeof(SeqListNode));
	}
	if (ret != NULL) {
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (SeqListNode)(ret + 1);
	}
	return ret;
}

void SeqListDestroy(SeqList list) {		//O(1)
	if (list != NULL) {
		free(list);
	}
}

void SeqListClear(SeqList list) {		//O(1)
	TSeqList t = (TSeqList)list;
	if (t != NULL) {
		t->length = 0;
	}
}

int SeqListLength(SeqList list) {		//O(1)
	TSeqList t = (TSeqList)list;
	int ret = -1;
	if (t != NULL) {
		ret = t->length;
	}
	return ret;
}

int SeqListCapacity(SeqList list) {		//O(1)
	TSeqList t = (TSeqList)list;
	int ret = -1;
	if (t != NULL) {
		ret = t->capacity;
	}
	return ret;
}

int SeqListInsert(SeqList list, SeqListNode node, int pos) {	//O(n)
	TSeqList t = (TSeqList)list;
	int i = 0;
	int ret = (t != NULL) && (t->length < t->capacity) && (pos >= 0);
	if (ret) {
		for (i = t->length; i > pos; i--) {
			t->node[i] = t->node[i - 1];
		}
		t->node[i] = node;
		t->length++;
	}
	return ret;
}

SeqListNode SeqListGet(SeqList list, int pos) {			//O(1)
	TSeqList t = (TSeqList)list;
	SeqListNode ret = NULL;
	if ((t != NULL) && (0 <= pos) && (pos < t->length)) {
		ret = t->node[pos];
	}
	return ret;
}

SeqListNode SeqListDelete(SeqList list, int pos) {		//O(n)
	TSeqList t = (TSeqList)list;
	SeqListNode ret = NULL;
	int i = 0;
	if ((t != NULL) && (0 <= pos) && (pos < t->length)) {
		ret = t->node[pos];
		for (i = pos + 1; i < t->length; i++) {
			t->node[i - 1] = t->node[i];
		}
		t->length--;
	}
	return ret;
}

// void print(SeqList list) {		//O(n)
	// TSeqList t = (TSeqList)list;
	// int i = 0;
	// for (; i < t->length; i++) {
		// printf("%d\t", *((int *)t->node[i]));
	// }
	// printf("\n");
// }
