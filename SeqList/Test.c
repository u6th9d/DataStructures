#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

int main() {
	SeqList list = SeqListCreate(10);
	int i = 0;
	int *p = NULL;
	int arr[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	while (i < 11) {
		SeqListInsert(list, &arr[i], i);
		i++;
	}
	print(list);
	p = SeqListGet(list, 3);
	printf("%d\n", *p);

	SeqListDelete(list, 0);
	SeqListDelete(list, 2);
	SeqListDelete(list, 4);
	SeqListDelete(list, 6);
	print(list);



	printf("%d\t%d\n", SeqListCapacity(list), SeqListLength(list));

	SeqListClear(list);
	printf("%d\t%d\n", SeqListCapacity(list), SeqListLength(list));
	SeqListDestroy(list);
	printf("%d\t%d\n", SeqListCapacity(list), SeqListLength(list));

	system("pause");
	return 0;
}