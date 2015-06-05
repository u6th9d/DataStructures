#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

int test1() {
	LinkStack* stack = NULL;
	stack = LinkStack_Create(10);
	char buf[] = "denghao";
	size_t length = strlen(buf);
	size_t i = length;
	while (i-- != 0) {
		LinkStack_Push(stack, &buf[i]);
	}

	printf("Top: %c\n", *(char*)LinkStack_Top(stack));
	printf("Length: %d\n", LinkStack_Size(stack));

	for (i = 0; i < length; i++) {
		printf("Pop: %c\n", *(char*)LinkStack_Pop(stack));
	}
	printf("\n");
	LinkStack_Destroy(stack);

	return 0;
}

int test2() {
	LinkStack* stack = LinkStack_Create();
	int a[16];
	int i = 0;

	for (i = 0; i<10; i++) {
		a[i] = i;

		LinkStack_Push(stack, a + i);
	}

	printf("Top: %d\n", *(int*)LinkStack_Top(stack));
	printf("Length: %d\n", LinkStack_Size(stack));

	while (LinkStack_Size(stack) > 0) {
		printf("Pop: %d\n", *(int*)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
	return 0;
}

int main() {
	test1();
	test2();

	system("pause");
	return 0;
}