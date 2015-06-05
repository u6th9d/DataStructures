#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

typedef struct _tag_SeqQueue {
	int length;
	int capacity;
	void** node;
}TSeqQueue;

SeqQueue* SeqQueue_Create(int capacity) {
	TSeqQueue* ret = NULL;
	if (capacity >= 0) {
		ret = (TSeqQueue*)malloc(sizeof(TSeqQueue) + capacity * sizeof(void*));
		if (ret != NULL) {
			ret->capacity = capacity;
			ret->length = 0;
			ret->node = (void**)(ret + 1);
		}
	}
	return ret;
}

int SeqQueue_Destroy(SeqQueue* queue) {
	int ret = (queue != NULL);
	if (ret) {
		free(queue);
	}
	return ret;
}

int SeqQueue_Clear(SeqQueue* queue) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	int ret = (tQueue != NULL);
	if (ret) {
		tQueue->length = 0;
	}
	return ret;
}

int SeqQueue_Append(SeqQueue* queue, void* item) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	int ret = (tQueue != NULL);
	ret = (tQueue->capacity > tQueue->length);
	if (ret) {
		tQueue->node[tQueue->length] = item;
		tQueue->length++;
	}
	return ret;
}

void* SeqQueue_Retrieve(SeqQueue* queue) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	void* ret = NULL;
	int i = 0;
	if (tQueue != NULL) {
		ret = tQueue->node[0];
		for (i = 1; i < tQueue->length; i++) {
			tQueue->node[i - 1] = tQueue->node[i];
		}
		tQueue->length--;
	}
	return ret;
}

void* SeqQueue_Header(SeqQueue* queue) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	void* ret = NULL;
	if (tQueue != NULL) {
		ret = tQueue->node[0];
	}
	return ret;
}

int SeqQueue_Length(SeqQueue* queue) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	int ret = -1;
	if (tQueue != NULL) {
		ret = tQueue->length;
	}
	return ret;
}

int SeqQueue_Capacity(SeqQueue* queue) {
	TSeqQueue* tQueue = (TSeqQueue*)queue;
	int ret = -1;
	if (tQueue != NULL) {
		ret = tQueue->capacity;
	}
	return ret;
}