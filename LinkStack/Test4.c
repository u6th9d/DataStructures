#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

int isNum(char ch) {
	return ('0' <= ch) && (ch <= '9');
}

int isOperator(char ch) {
	return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%');
}

int excute(int left, char ch, int right) {
	int ret;
	switch (ch) {
	case '+': ret = left + right; break;
	case '-': ret = left - right; break;
	case '*': ret = left * right; break;
	case '/': ret = left / right; break;
	case '%': ret = left % right; break;
	}
	return ret + '0';
}

int compute(const char* str) {
	int i = 0;
	LinkStack* stack;
	if (str == NULL) {
		return -1;
	}
	stack = LinkStack_Create();
	while (str[i] != '\0') {
		if (isNum(str[i])) {
			LinkStack_Push(stack, (void*)str[i]);
		}
		else if (isOperator(str[i])) {
			int right = (char)LinkStack_Pop(stack) - '0';
			int left = (char)LinkStack_Pop(stack) - '0';
			LinkStack_Push(stack, (void*)excute(left, str[i], right));
		}
		else {
			printf("Error!\n");
			return -1;
		}
		i++;
	}
	printf("%d\n", (char)LinkStack_Pop(stack) - '0');
	LinkStack_Destroy(stack);
	return 0;
}


int main() {
	char *ptr = "21295-*3%+*4/";
	printf("%d\n", compute(ptr));
	system("pause");
}