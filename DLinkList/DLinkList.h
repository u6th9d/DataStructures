#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef void DLinkList;

typedef struct _tag_DLinkListNode {
	struct _tag_DLinkListNode* next;
	struct _tag_DLinkListNode* prev;
}DLinkListNode;

DLinkList* DLinkListCreate();

int DLinkListDestroy(DLinkList* list);

int DLinkListClear(DLinkList* list);

int DLinkListLength(DLinkList* list);

int DLinkListInsert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkListGet(DLinkList* list, int pos);

DLinkListNode* DLinkListDelete(DLinkList* list, int pos);

DLinkListNode* DLinkListDeleteNode(DLinkList* list, DLinkListNode* node);

DLinkListNode* DLinkListReset(DLinkList* list);

DLinkListNode* DLinkListCurrent(DLinkList* list);

DLinkListNode* DLinkListNext(DLinkList* list);

DLinkListNode* DLinkListPrev(DLinkList* list);

#endif