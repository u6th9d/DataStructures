#ifndef _SEQQUEUE_H_
#define _SEQQUEUE_H_

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);

int SeqQueue_Destroy(SeqQueue* queue);

int SeqQueue_Clear(SeqQueue* queue);

int SeqQueue_Append(SeqQueue* queue, void* item);

void* SeqQueue_Retrieve(SeqQueue* queue);

void* SeqQueue_Header(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);

#endif
