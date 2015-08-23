/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#ifndef _STACK_H_
#define _STACK_H_

#define DEFAULT_CAPACITY 8

typedef struct stack {
	char* p_elem;
	int size, capacity, typesize;
}Stack;

void stack_init(Stack* s, int typesize);

int stack_empty(Stack* s);

void stack_push(Stack* s, void* src);

void stack_top(Stack* s, void* dst);

void stack_pop(Stack* s, void* dst);

void stack_destroy(Stack* s);

#endif