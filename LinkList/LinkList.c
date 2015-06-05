#include<stdio.h>
#include<malloc.h>
#include"LinkList.h"

typedef struct tag_LinkListNode {
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkListCreate() {
	TLinkList* ret = NULL;
	ret = (TLinkList *)malloc(sizeof(TLinkList));
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->length = 0;
	}
	return (LinkList *)ret;
}

int LinkListLength(LinkList* list) {
	TLinkList* tList = (TLinkList *)list;
	int ret = -1;
	if (tList != NULL) {
		ret = tList->length;
	}
	return ret;
}

int LinkListInsert(LinkList* list, LinkListNode* node, int pos) {
	TLinkList* tList = (TLinkList *)list;
	LinkListNode* current = (LinkListNode *)list;
	int ret = (tList != NULL) && (node != NULL) && (0 <= pos);
	int i = 0;
	if (ret) {
		for (i = 0; (i < pos) && (current->next != NULL); i++) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
		tList->length++;
	}
	return ret;
}

LinkListNode* LinkListDelete(LinkList* list, int pos) {
	TLinkList* tList = (TLinkList *)list;
	LinkListNode* current = (LinkListNode *)list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((tList != NULL) && (0 <= pos) && (pos < tList->length)) {
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
		current->next = ret->next;
		tList->length--;
	}
	return ret;
}

LinkListNode* LinkListGet(LinkList* list, int pos) {
	TLinkList* tList = (TLinkList *)list;
	LinkListNode* current = (LinkListNode *)list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((tList != NULL) && (0 <= pos) && (pos < tList->length)) {
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

int LinkListClear(LinkList* list) {
	TLinkList* tList = (TLinkList *)list;
	int ret = (tList != NULL);
	if (ret) {
		tList->length = 0;
		tList->header.next = NULL;
	}
	return ret;
}

int LinkListDestroy(LinkList* list) {
	int ret = (list != NULL);
	if (ret) {
		free(list);
	}
	return ret;
}

LinkList* LinkListReverse(LinkList* list) {
	TLinkList* ret = (TLinkList *)list;
	LinkListNode* current = (LinkListNode*)list;
	LinkListNode* tmp;
	if (ret != NULL) {
		current = current->next;
		ret->header.next = NULL;
		while (current != NULL) {
			tmp = current->next;
			LinkListInsert(ret, current, 0);
			current = tmp;
		}
	}
	return ret;
}