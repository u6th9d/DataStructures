#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

typedef struct _tag_Stack {
	int capacity;
	int length;
	void** node;
}TStack;

SeqStack* SeqStack_Create(int capacity) {
	TStack* ret = NULL;
	if (capacity >= 0) {
		ret = (SeqStack*)malloc(sizeof(TStack) + sizeof(void*) * capacity);
		if (ret != NULL) {
			ret->capacity = capacity;
			ret->length = 0;
			ret->node = (void**)(ret + 1);
		}
	}
	return ret;
}

int SeqStack_Destroy(SeqStack* stack) {
	int ret = (stack != NULL);
	if (ret) {
		free(stack);
	}
	return ret;
}

int SeqStack_Clear(SeqStack* stack) {
	TStack* tStack = (TStack*)stack;
	int ret = (tStack != NULL);
	if (ret) {
		tStack->length = 0;
	}
	return ret;
}

int SeqStack_Push(SeqStack* stack, void* item) {
	TStack* tStack = (TStack*)stack;
	int ret = (tStack != NULL) && (item != NULL) && (tStack->length < tStack->capacity);
	if (ret) {
		tStack->node[tStack->length] = item;
		tStack->length++;
	}
	return ret;
}

void* SeqStack_Pop(SeqStack* stack) {
	TStack* tStack = (TStack*)stack;
	void* ret = NULL;
	if ((tStack != NULL) && (tStack->length != 0)) {
		ret = tStack->node[tStack->length - 1];
		//tStack->node[tStack->length - 1] = NULL;	//Erase
		tStack->length--;
	}
	return ret;
}

void* SeqStack_Top(SeqStack* stack) {
	TStack* tStack = (TStack*)stack;
	void* ret = NULL;
	if ((tStack != NULL) && (tStack->length != 0)) {
		ret = tStack->node[tStack->length - 1];
	}
	return ret;
}

int SeqStack_Length(SeqStack* stack) {
	TStack* tStack = (TStack*)stack;
	int ret = -1;
	if (tStack != NULL) {
		ret = tStack->length;
	}
	return ret;
}

int SeqStack_Capacity(SeqStack* stack) {
	TStack* tStack = (TStack*)stack;
	int ret = -1;
	if (tStack != NULL) {
		ret = tStack->capacity;
	}
	return ret;
}