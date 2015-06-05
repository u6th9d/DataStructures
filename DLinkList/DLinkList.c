#include<stdio.h>
#include<stdlib.h>
#include"DLinkList.h"

typedef struct tag_DLinkListNode {
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

DLinkList* DLinkListCreate() {
	TDLinkList* ret = NULL;
	ret = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->header.prev = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}
	return ret;
}

int DLinkListDestroy(DLinkList* list) {
	int ret = (list != NULL);
	if (ret) {
		free(list);
	}
	return ret;
}

int DLinkListClear(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	int ret = (tdList != NULL);
	if (ret) {
		tdList->header.next = NULL;
		tdList->header.prev = NULL;
		tdList->slider = NULL;
		tdList->length = 0;
	}
	return ret;
}

int DLinkListLength(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	int ret = -1;
	if (tdList != NULL) {
		ret = tdList->length;
	}
	return ret;
}

int DLinkListInsert(DLinkList* list, DLinkListNode* node, int pos) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)list;
	DLinkListNode* next = NULL;
	int i, ret = (tdList != NULL) && (node != NULL) && (pos >= 0);
	if (ret) {
		for (i = 0; (i < pos) && (current->next != NULL); i++) {
			current = current->next;
		}
		next = current->next;

		node->next = next;
		current->next = node;

		if (next != NULL) {
			next->prev = node;
		}
		node->prev = current;

		if (tdList->length == 0) {
			tdList->slider = node;
		}
		if (current == (DLinkListNode*)tdList) {
			node->prev = NULL;
		}
		tdList->length++;
	}
	return ret;
}

DLinkListNode* DLinkListGet(DLinkList* list, int pos) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)list;
	DLinkListNode* ret = NULL;
	int i;
	if ((tdList != NULL) && (0 <= pos) && (pos < tdList->length)) {
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

DLinkListNode* DLinkListDelete(DLinkList* list, int pos) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)list;
	DLinkListNode* next = NULL;
	DLinkListNode* ret = NULL;
	int i;
	if ((tdList != NULL) && (0 <= pos) && (pos < tdList->length)) {
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
		next = ret->next;
		current->next = next;
		if (next != NULL) {
			next->prev = current;
			if (pos != 0) {
				next->prev = NULL;
			}
			/*if (current == (DLinkListNode*)tdList) {
				next->prev = NULL;
			}*/
		}
		if (tdList->slider == ret) {
			tdList->slider = next;
		}
		tdList->length--;
	}
	return ret;
}

DLinkListNode* DLinkListDeleteNode(DLinkList* list, DLinkListNode* node) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)list;
	DLinkListNode* ret = NULL;
	int i;
	if ((tdList != NULL) && (node != NULL)) {
		for (i = 0; i < tdList->length; i++) {
			if (current->next == node) {
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret != NULL) {
			DLinkListDelete(list, i);
		}
	}
	return ret;
}

DLinkListNode* DLinkListReset(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (tdList != NULL) {
		tdList->slider = tdList->header.next;
		ret = tdList->slider;
	}
	return ret;
}

DLinkListNode* DLinkListCurrent(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (tdList != NULL) {
		ret = tdList->slider;
	}
	return ret;
}

DLinkListNode* DLinkListNext(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if ((tdList != NULL) && (tdList->slider != NULL)) {
		ret = tdList->slider;
		tdList->slider = ret->next;
	}
	return ret;
}

DLinkListNode* DLinkListPrev(DLinkList* list) {
	TDLinkList* tdList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if ((tdList != NULL) && (tdList->slider != NULL)) {
		ret = tdList->slider;
		tdList->slider = ret->prev;
	}
	return ret;
}
