#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;

typedef struct _LinkListNode {
	struct _LinkListNode* next;
}LinkListNode;

LinkList* LinkListCreate();

int LinkListLength(LinkList* list);

int LinkListInsert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkListDelete(LinkList* list, int pos);

LinkListNode* LinkListGet(LinkList* list, int pos);

int LinkListClear(LinkList* list);

int LinkListDestroy(LinkList* list);

LinkList* LinkListReverse(LinkList* list);

#endif