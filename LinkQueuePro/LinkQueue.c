#include<stdio.h>
#include<stdlib.h>
#include"LinkQueue.h"

typedef struct _tag_LinkQueue {
	LinkQueueNode header;
	LinkQueueNode* slider;
	int length;
}TLinkQueue;

typedef struct _LinkQueueData {
	LinkQueueNode* next;
	void* item;
}LinkQueueData;

LinkQueue* LinkQueue_Create() {
	TLinkQueue*ret = NULL;
	ret = (TLinkQueue*)malloc(sizeof(TLinkQueue));
	if (ret != NULL) {
		ret->header.next = NULL;
		ret->slider = NULL;
		ret->length = 0;
	}
	return ret;
}

int LinkQueue_Destroy(LinkQueue* queue) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	int ret = (tQueue != NULL);
	if (ret) {
		LinkQueue_Clear(tQueue);
		free(tQueue);
	}
	return ret;
}

int LinkQueue_Clear(LinkQueue* queue) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	int ret = (tQueue != NULL);
	int i = 0;
	if (ret) {
		for (i = 0; i < tQueue->length; i++) {
			LinkQueue_Retrieve(tQueue);
		}
		tQueue->slider = NULL;
		tQueue->length = 0;
	}
	return ret;
}

int LinkQueue_Append(LinkQueue* queue, void* item) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	LinkQueueData* node = NULL;
	int ret = (tQueue != NULL) && (item != NULL);
	if (ret) {
		node = (LinkQueueData*)malloc(sizeof(LinkQueueData));
		if (node != NULL) {
			node->item = item;
			node->next = NULL;

			if (tQueue->slider == NULL) /*or tQueue->length == 0*/ {
				tQueue->header.next = (LinkQueueNode*)node;
				tQueue->slider = (LinkQueueNode*)node;
			}
			else {
				tQueue->slider->next = (LinkQueueNode*)node;
				tQueue->slider = (LinkQueueNode*)node;
			}
			tQueue->length++;
		}
	}
	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	LinkQueueData* node = NULL;
	void* ret = NULL;
	if ((tQueue != NULL) && (tQueue->length > 0)) {
		node = (LinkQueueData*)tQueue->header.next;
		tQueue->header.next = node->next;
		ret = node->item;
		free(node);
		tQueue->length--;

		if (tQueue->length == 0) {
			tQueue->slider = NULL;
		}
	}
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	LinkQueueData* node = NULL;
	void* ret = NULL;
	if ((tQueue != NULL) && (tQueue->length > 0)) {
		node = (LinkQueueData*)tQueue->header.next;
		ret = node->item;
	}
	return ret;
}

int LinkQueue_Length(LinkQueue* queue) {
	TLinkQueue* tQueue = (TLinkQueue*)queue;
	int ret = -1;
	if (tQueue != NULL) {
		ret = tQueue->length;
	}
	return ret;
}