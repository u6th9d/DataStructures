#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

int test1() {
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	char buf[] = "denghao";
	size_t length = strlen(buf);
	size_t i = length;
	while (i-- != 0) {
		SeqStack_Push(stack, &buf[i]);
	}

	printf("Top: %c\n", *(char*)SeqStack_Top(stack));
	printf("Capacity: %d\n", SeqStack_Capacity(stack));
	printf("Length: %d\n", SeqStack_Length(stack));

	for (i = 0; i < length; i++) {
		printf("Pop: %c\n", *(char*)SeqStack_Pop(stack));
	}
	printf("\n");
	SeqStack_Destroy(stack);

	return 0;
}

int test2() {
	SeqStack* stack = SeqStack_Create(20);
	int a[10];
	int i = 0;

	for (i = 0; i<10; i++) {
		a[i] = i;

		SeqStack_Push(stack, a + i);
	}

	printf("Top: %d\n", *(int*)SeqStack_Top(stack));
	printf("Capacity: %d\n", SeqStack_Capacity(stack));
	printf("Length: %d\n", SeqStack_Length(stack));

	while (SeqStack_Length(stack) > 0) {
		printf("Pop: %d\n", *(int*)SeqStack_Pop(stack));
	}
	printf("\n");
	SeqStack_Destroy(stack);

	return 0;
}

int main() {
	test1();
	test2();

	system("pause");
	return 0;
}