#include<stdio.h>
#include<malloc.h>
#include"CircleList.h"

typedef struct tag_CircleListNode {
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

CircleList* CircleListCreate() {		//O(1)
	TCircleList* ret = NULL;
	ret = (TCircleList *)malloc(sizeof(TCircleList));
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}
	return (CircleList *)ret;
}

int CircleListLength(CircleList* list) {		//O(1)
	TCircleList* tList = (TCircleList *)list;
	int ret = -1;
	if (tList != NULL) {
		ret = tList->length;
	}
	return ret;
}

int CircleListInsert(CircleList* list, CircleListNode* node, int pos) {		//O(n)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* current = (CircleListNode *)list;
	int ret = (tList != NULL) && (node != NULL) && (0 <= pos);
	int i = 0;
	if (ret) {
		for (i = 0; (i < pos) && (current->next != NULL); i++) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;

		//Create circle
		if (tList->length == 0) {
			node->next = node;
			tList->slider = node;
		}
		else if (pos == 0) {
			current = current->next->next;
			while (current->next != node->next) {
				current = current->next;
			}
			current->next = node;
		}

		tList->length++;
	}
	return ret;
}

CircleListNode* CircleListDelete(CircleList* list, int pos) {		//O(n)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* current = (CircleListNode *)list;
	CircleListNode* ret = NULL;
	int i, p;

	if ((tList != NULL) && (tList->length != 0)) {
		p = pos % tList->length;
		if (tList->length == 1) {
			ret = current->next;
			tList->header.next = NULL;
			tList->slider = NULL;
		}
		else {
			if (p == 0) {
				tList->header.next = current->next->next;
				tList->slider = tList->header.next;
				p = tList->length - 1;
			}
			for (i = 0; i < p; i++) {
				current = current->next;
			}
			ret = current->next;
			current->next = ret->next;
			if (tList->slider == ret) {
				tList->slider = ret->next;
			}
		}
		tList->length--;
	}

	return ret;
}

CircleListNode* CircleListGet(CircleList* list, int pos) {	//O(n)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* current = (CircleListNode *)list;
	CircleListNode* ret = NULL;
	int i, p;
	if ((tList != NULL) && (pos >= 0) && tList->length != 0) {
		p = pos % tList->length;
		for (i = 0; i < p; i++) {
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

int CircleListClear(CircleList* list) {			//O(1)
	TCircleList* tList = (TCircleList *)list;
	int ret = (tList != NULL);
	if (ret) {
		tList->length = 0;
		tList->header.next = NULL;
		tList->slider = NULL;
	}
	return ret;
}

int CircleListDestroy(CircleList* list) {		//O(1)
	int ret = (list != NULL);
	if (ret) {
		free(list);
	}
	return ret;
}

CircleListNode* CircleListDeleteNode(CircleList* list, CircleListNode* node) {		//O(n)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* current = (CircleListNode *)list;
	CircleListNode* ret = NULL;
	int pos = 0;
	if (tList != NULL) {
		for (pos = 0; pos < tList->length; pos++) {
			if (current->next == node) {
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret != NULL) {
			CircleListDelete(tList, pos);
		}
	}
	return ret;
}

CircleListNode* CircleListReset(CircleList* list) {			//O(1)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (tList != NULL) {
		tList->slider = tList->header.next;
		ret = tList->slider;
	}
	return ret;
}

CircleListNode* CircleListCurrent(CircleList* list) {		//O(1)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if (tList != NULL) {
		ret = tList->slider;
	}
	return ret;
}

CircleListNode* CircleListNext(CircleList* list) {			//O(1)
	TCircleList* tList = (TCircleList *)list;
	CircleListNode* ret = NULL;
	if ((tList != NULL) && (tList->slider != NULL)) {
		ret = tList->slider;
		tList->slider = ret->next;
	}
	return ret;
}


//CircleListNode* CircleListDelete(CircleList* list, int pos) {		//O(n)
//	TCircleList* tList = (TCircleList *)list;
//	CircleListNode* current = (CircleListNode *)list;
//	CircleListNode* ret = NULL;
//	int i, p;
//
//	if ((tList != NULL) && (tList->length != 0)) {
//		if (tList->length == 1) {
//			ret = current->next;
//			current->next = NULL;
//		}
//		else if (pos % tList->length == 0) {
//			ret = current->next;
//			current->next = ret->next;
//			current = ret->next;
//			while (ret != current->next) {
//				current = current->next;
//			}
//			current->next = ret->next;
//		}
//		else {
//			for (i = 0; i < pos; i++) {
//				current = current->next;
//			}
//			ret = current->next;
//			current->next = ret->next;
//		}
//		tList->length--;
//	}
//	return ret;
//}
