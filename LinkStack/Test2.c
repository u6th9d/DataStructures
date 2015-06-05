#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int isLeft(char c) {
	int ret = 0;

	switch (c) {
	case '<':
	case '(':
	case '[':
	case '{':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int isRight(char c) {
	int ret = 0;

	switch (c) {
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int match(char left, char right) {
	int ret = 0;

	switch (left) {
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int scanner(const char* code) {
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while (code[i] != '\0') {
		if (isLeft(code[i])) {
			LinkStack_Push(stack, (void*)(code + i));
		}

		if (isRight(code[i])) {
			char* c = (char*)LinkStack_Pop(stack);

			if ((c == NULL) || !match(*c, code[i])) {
				printf("%c does not match!\n", code[i]);
				ret = 0;
				break;
			}
		}

		i++;
	}

	if ((LinkStack_Size(stack) == 0) && (code[i] == '\0')) {
		printf("Succeed!\n");
		ret = 1;
	}
	else {
		printf("Invalid code!\n");
		ret = 0;
	}

	LinkStack_Destroy(stack);

	return ret;
}

int main(int argc, char *argv[]) {
	const char* code = "#include <stdio.h> int main() { int a[5][5]; int (*p)[4]; p = a[0]; printf(\"%d\\n\", &p[3][3] - &a[3][3]); return 0; }";

	scanner(code);
	system("pause");
	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int isNumber(char c) {
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c) {
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c) {
	return (c == '(');
}

int isRight(char c) {
	return (c == ')');
}

int priority(char c) {
	int ret = 0;

	if ((c == '+') || (c == '-')) {
		ret = 1;
	}

	if ((c == '*') || (c == '/')) {
		ret = 2;
	}

	return ret;
}

void output(char c) {
	if (c != '\0') {
		printf("%c", c);
	}
}

void transform(const char* exp) {
	LinkStack* stack = LinkStack_Create();
	int i = 0;

	while (exp[i] != '\0') {
		if (isNumber(exp[i])) {
			output(exp[i]);
		}
		else if (isOperator(exp[i])) {
			while (priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack))) {
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Push(stack, (void*)(int)exp[i]);
		}
		else if (isLeft(exp[i])) {
			LinkStack_Push(stack, (void*)(int)exp[i]);
		}
		else if (isRight(exp[i])) {
			char c = '\0';

			while (!isLeft((char)(int)LinkStack_Top(stack))) {
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Pop(stack);
		}
		else {
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	while ((LinkStack_Size(stack) > 0) && (exp[i] == '\0')) {
		output((char)(int)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
}

int main() {
	transform("9+(3-1)*5+8/2");

	printf("\n");
	system("pause");
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int isNumber(char c) {
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c) {
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c) {
	return (c - '0');
}

int express(int left, int right, char op) {
	int ret = 0;

	switch (op) {
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}

int compute(const char* exp) {
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while (exp[i] != '\0') {
		if (isNumber(exp[i])) {
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if (isOperator(exp[i])) {
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left, right, exp[i]);

			LinkStack_Push(stack, (void*)result);
		}
		else {
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if ((LinkStack_Size(stack) == 1) && (exp[i] == '\0')) {
		ret = (int)LinkStack_Pop(stack);
	}
	else {
		printf("Invalid expression!");
	}

	LinkStack_Destroy(stack);

	return ret;
}

int main() {
	printf("9 + (3 - 1) * 5 + 8 / 2 = %d\n", compute("931-5*+82/+"));

	system("pause");
}
*/
