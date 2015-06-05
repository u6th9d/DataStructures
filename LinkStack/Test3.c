#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

int isSpace(char ch) {
	return (ch == ' ');
}

int isNum(char ch) {
	return ('0' <= ch) && (ch <= '9');
}

int isOperator(char ch) {
	return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%');
}

int isLeft(char ch) {
	return (ch == '(');
}

int isRight(char ch) {
	return (ch == ')');
}

int priority(char ch) {
	int ret = 0;
	if ((ch == '+') || (ch == '-')) {
		ret = 1;
	}
	else if ((ch == '*') || (ch == '/') || (ch == '%')) {
		ret = 2;
	}
	return ret;
}

void print(char ch) {
	printf("%c ", ch);
}

int transform(const char* str) {
	int i = 0;
	LinkStack* stack;
	if (str == NULL) {
		return -1;
	}
	stack = LinkStack_Create();
	while (str[i] != '\0') {
		if (!isSpace(str[i])) {
			if (isNum(str[i])) {
				print(str[i]);
			}
			else if (isOperator(str[i])) {
				while (priority(str[i]) <= priority((char)LinkStack_Top(stack))) {
					print((char)LinkStack_Pop(stack));
				}
				LinkStack_Push(stack, (void*)str[i]);
			}
			else if (isLeft(str[i])) {
				LinkStack_Push(stack, (void*)str[i]);
			}
			else if (isRight(str[i])) {
				while (!isLeft((char)LinkStack_Top(stack))) {
					print((char)LinkStack_Pop(stack));
				}
				LinkStack_Pop(stack);
			}
			else {
				printf("Invalid expression!");
				break;
			}
		}
		i++;
	}
	while ((LinkStack_Size(stack) > 0) && (str[i]) == '\0') {
		print((char)LinkStack_Pop(stack));
	}
	LinkStack_Destroy(stack);
	return 0;
}

int main() {
	char *ptr = "2 * ( 1 + 2 * ( 9 - 5 ) % 3 ) / 4";
	transform(ptr);
	printf("\n\n");
	system("pause");
	return 0;
}
