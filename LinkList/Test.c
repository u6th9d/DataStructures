#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

typedef struct _value {
	LinkListNode next;
	int num;
}Value;

int main() {
	Value v1, v2, v3, v4, v5;
	Value *p = NULL;
	LinkList *list = LinkListCreate();
	v1.num = 1;
	v2.num = 2;
	v3.num = 3;
	v4.num = 4;
	v5.num = 5;


	LinkListInsert(list, (LinkListNode*)&v1, 0);
	printf("%d\n", LinkListLength(list));

	LinkListInsert(list, (LinkListNode*)&v2, 0);
	printf("%d\n", LinkListLength(list));

	LinkListInsert(list, (LinkListNode*)&v3, 0);
	printf("%d\n", LinkListLength(list));

	LinkListInsert(list, (LinkListNode*)&v4, 0);
	printf("%d\n", LinkListLength(list));

	LinkListInsert(list, (LinkListNode*)&v5, 0);
	printf("%d\n\n", LinkListLength(list));


	LinkListReverse(list);


	p = (Value*)LinkListGet(list, 0);
	printf("%d\n", p->num);
	LinkListDelete(list, 0);

	p = (Value*)LinkListGet(list, 0);
	printf("%d\n", p->num);
	LinkListDelete(list, 0);

	p = (Value*)LinkListGet(list, 0);
	printf("%d\n", p->num);
	LinkListDelete(list, 0);

	p = (Value*)LinkListGet(list, 0);
	printf("%d\n", p->num);
	LinkListDelete(list, 0);

	p = (Value*)LinkListGet(list, 0);
	printf("%d\n\n", p->num);
	LinkListDelete(list, 0);


	LinkListClear(list);
	printf("%d\n", LinkListLength(list));

	LinkListDestroy(list);
	printf("%d\n", LinkListLength(list));

	system("pause");
	return 0;
}