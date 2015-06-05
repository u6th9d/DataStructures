#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;

typedef struct _CircleListNode {
	struct _CircleListNode* next;
}CircleListNode;

CircleList* CircleListCreate();

int CircleListLength(CircleList* list);

int CircleListInsert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleListDelete(CircleList* list, int pos);

CircleListNode* CircleListGet(CircleList* list, int pos);

int CircleListClear(CircleList* list);

int CircleListDestroy(CircleList* list);

CircleListNode* CircleListDeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleListReset(CircleList* list);

CircleListNode* CircleListCurrent(CircleList* list);

CircleListNode* CircleListNext(CircleList* list);

#endif