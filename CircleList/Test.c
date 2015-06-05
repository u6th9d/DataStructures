#include<stdio.h>
#include<stdlib.h>
#include"CircleList.h"

typedef struct _Value {
	CircleListNode next;
	int num;
}Value;

int test1() {
	CircleList* list = CircleListCreate();
	Value* tmp = NULL;
	Value v1, v2, v3, v4, v5;
	int i = 0;
	tmp = (Value*)CircleListGet(list, 7);
	v1.num = 1;
	v2.num = 2;
	v3.num = 3;
	v4.num = 4;
	v5.num = 5;

	CircleListInsert(list, (CircleListNode*)&v1, 0);
	CircleListInsert(list, (CircleListNode*)&v2, 1);
	CircleListInsert(list, (CircleListNode*)&v3, 2);
	CircleListInsert(list, (CircleListNode*)&v4, 3);
	CircleListInsert(list, (CircleListNode*)&v5, 4);
	printf("length = %d\n\n", CircleListLength(list));

	//CircleListDelete(list, 1);
	//printf("%d\n", CircleListLength(list));

	//CircleListDelete(list, 5);
	//printf("%d\n", CircleListLength(list));

	CircleListDeleteNode(list, (CircleListNode*)&v4);

	for (tmp = &v1; tmp->next.next != NULL; tmp = (Value*)tmp->next.next) {
		printf("value%d = %d\n", tmp->num, tmp->num);
		if (i++ == 20) {
			printf("\n");
			break;
		}
	}

	tmp = (Value*)CircleListGet(list, 7);
	printf("value = %d\n\n", tmp->num);

	CircleListClear(list);
	printf("length = %d\n\n", CircleListLength(list));

	CircleListDestroy(list);

	return 0;
}

int test2() {
	CircleList* list = CircleListCreate();
	Value* tmp = NULL;
	Value v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12;
	int i = 0;
	v1.num = 1;
	v2.num = 2;
	v3.num = 3;
	v4.num = 4;
	v5.num = 5;
	v6.num = 6;
	v7.num = 7;
	v8.num = 8;
	v9.num = 9;
	v10.num = 10;
	v11.num = 11;
	v12.num = 12;

	CircleListInsert(list, (CircleListNode*)&v1, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v2, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v3, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v4, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v5, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v6, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v7, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v8, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v9, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v10, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v11, CircleListLength(list));
	CircleListInsert(list, (CircleListNode*)&v12, CircleListLength(list));

	for (tmp = &v1; tmp->next.next != NULL; tmp = (Value*)tmp->next.next) {
		printf("value%d = %d\n", tmp->num, tmp->num);
		if (i++ == 20) {
			printf("\n");
			break;
		}
	}

	while (CircleListLength(list) != 0) {
		for (i = 1; i < 17; i++) {
			CircleListNext(list);
		}
		tmp = (Value*)CircleListCurrent(list);
		printf("%d ", tmp->num);
		CircleListDeleteNode(list, (CircleListNode*)tmp);
	}

	printf("\n");
	CircleListDestroy(list);
	return 0;
}

int main() {
	test1();
	test2();
	system("pause");
	return 0;
}