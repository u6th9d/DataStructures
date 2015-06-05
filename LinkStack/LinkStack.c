#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

typedef struct _tag_LinkStack {
	LinkStackNode header;
	int size;
}TLinkStack;

typedef struct _LinkStackData {
	LinkStackNode* next;
	void* item;
}LinkStackData;

LinkStack* LinkStack_Create() {
	TLinkStack* ret = NULL;
	ret = (TLinkStack*)malloc(sizeof(TLinkStack));
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->size = 0;
	}
	return ret;
}

int LinkStack_Destroy(LinkStack* stack) {
	int ret = (stack != NULL);
	if (ret) {
		LinkStack_Clear(stack);
		free(stack);
	}
	return ret;
}

int LinkStack_Clear(LinkStack* stack) {
	TLinkStack* tStack = (TLinkStack*)stack;
	int ret = (tStack != NULL);
	int i = 0;
	if (ret) {
		for (i = 0; i < tStack->size; i++) {
			LinkStack_Pop(tStack);
		}
		tStack->size = 0;
	}
	return ret;
}

int LinkStack_Push(LinkStack* stack, void* item) {
	TLinkStack* tStack = (TLinkStack*)stack;
	LinkStackData* node = NULL;
	int ret = (tStack != NULL) && (item != NULL);
	if (ret) {
		node = (LinkStackData*)malloc(sizeof(LinkStackData));
		ret = (node != NULL);
		if (ret) {
			node->item = item;
			node->next = tStack->header.next;
			tStack->header.next = (LinkStackNode*)node;
			tStack->size++;
		}
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack) {
	TLinkStack* tStack = (TLinkStack*)stack;
	LinkStackData* node = NULL;
	void* ret = NULL;
	if ((tStack != NULL) && (tStack->size) != 0) {
		node = (LinkStackData*)tStack->header.next;
		tStack->header.next = (LinkStackNode*)(node->next);
		ret = node->item;
		free(node);
		tStack->size--;
	}
	return ret;
}

void* LinkStack_Top(LinkStack* stack) {
	TLinkStack* tStack = (TLinkStack*)stack;
	LinkStackData* node = NULL;
	void* ret = NULL;
	if ((tStack != NULL) && (tStack->size) != 0) {
		node = (LinkStackData*)tStack->header.next;
		ret = node->item;
	}
	return ret;
}

int LinkStack_Size(LinkStack* stack) {
	TLinkStack* tStack = (TLinkStack*)stack;
	int ret = -1;
	if (tStack != NULL) {
		ret = tStack->size;
	}
	return ret;
}