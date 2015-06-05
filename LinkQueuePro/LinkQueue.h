#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef void LinkQueue;

typedef struct _LinkQueueNode {
	struct _LinkQueueNode* next;
}LinkQueueNode;

LinkQueue* LinkQueue_Create();

int LinkQueue_Destroy(LinkQueue* queue);

int LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Append(LinkQueue* queue, void* item);

void* LinkQueue_Retrieve(LinkQueue* queue);

void* LinkQueue_Header(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);

#endif