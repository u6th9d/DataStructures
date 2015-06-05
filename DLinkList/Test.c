#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

struct Value {
	DLinkListNode header;
	int v;
};

int main(int argc, char *argv[]) {
	int i = 0;
	DLinkList* list = DLinkListCreate();
	struct Value* pv = NULL;
	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	DLinkListInsert(list, (DLinkListNode*)&v1, DLinkListLength(list));
	DLinkListInsert(list, (DLinkListNode*)&v2, DLinkListLength(list));
	DLinkListInsert(list, (DLinkListNode*)&v3, DLinkListLength(list));
	DLinkListInsert(list, (DLinkListNode*)&v4, DLinkListLength(list));
	DLinkListInsert(list, (DLinkListNode*)&v5, DLinkListLength(list));

	for (i = 0; i<DLinkListLength(list); i++) {
		pv = (struct Value*)DLinkListGet(list, i);

		printf("%d\n", pv->v);
	}
	printf("\n");

	DLinkListDelete(list, DLinkListLength(list) - 1);
	DLinkListDelete(list, 0);

	for (i = 0; i<DLinkListLength(list); i++) {
		pv = (struct Value*)DLinkListNext(list);

		printf("%d\n", pv->v);
	}
	printf("\n");

	DLinkListReset(list);
	DLinkListNext(list);

	pv = (struct Value*)DLinkListCurrent(list);
	printf("%d\n", pv->v);
	DLinkListDeleteNode(list, (DLinkListNode*)pv);

	pv = (struct Value*)DLinkListCurrent(list);
	printf("%d\n", pv->v);
	DLinkListPrev(list);

	pv = (struct Value*)DLinkListCurrent(list);
	//printf("%d\n", pv->v);

	printf("Length: %d\n", DLinkListLength(list));
	DLinkListDestroy(list);

	system("pause");
	return 0;
}
