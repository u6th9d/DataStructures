/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

static void my_memcpy(void* dst, const void* src, int size) {
	char* d = (char*)dst;
	char* s = (char*)src;
	if (dst < src) {
		while (size--) {
			*d++ = *s++;
		}
	}
	else {
		d += size - 1;
		s += size - 1;
		while (size--) {
			*d-- = *s--;
		}
	}
}

static void stack_grow(Stack* s) {
	int new_capacity = s->capacity << 1;
	char* new_p_elem = (char*)malloc(new_capacity * s->typesize);	//realloc()
	assert(new_p_elem != NULL);
	my_memcpy(new_p_elem, s->p_elem, s->capacity * s->typesize);
	s->capacity = new_capacity;
	free(s->p_elem);
	s->p_elem = new_p_elem;
}

void stack_init(Stack* s, int n) {
	s->p_elem = (char*)malloc(DEFAULT_CAPACITY * n);
	assert(s->p_elem != NULL);
	s->capacity = DEFAULT_CAPACITY;
	s->size = 0;
	s->typesize = n;
}

int stack_empty(Stack* s) {
	return !(s->size);
}

void stack_top(Stack* s, void* dst) {
	if (s->size != 0) {
		my_memcpy(dst, s->p_elem + s->typesize*(s->size - 1), s->typesize);
	}
}

void stack_pop(Stack* s, void* dst) {
	if (s->size != 0) {
		my_memcpy(dst, s->p_elem + s->typesize*(s->size - 1), s->typesize);
		s->size--;
	}
}

void stack_push(Stack* s, void* src) {
	if (s->capacity == s->size) {
		stack_grow(s);
	}
	my_memcpy(s->p_elem + s->size * s->typesize, src, s->typesize);
	s->size++;
}

void stack_destroy(Stack* s) {
	free(s->p_elem);
}
