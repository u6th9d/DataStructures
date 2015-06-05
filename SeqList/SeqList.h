#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void* SeqList;
typedef void* SeqListNode;

SeqList SeqListCreate(int capacity);

void SeqListDestroy(SeqList list);

void SeqListClear(SeqList list);

int SeqListLength(SeqList list);

int SeqListCapacity(SeqList list);

int SeqListInsert(SeqList list, SeqListNode node, int pos);

SeqListNode SeqListGet(SeqList list, int pos);

SeqListNode SeqListDelete(SeqList list, int pos);

//
// void print(SeqList list);

#endif
