/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

static void my_memcpy(void* dst, const void* src, int size) {
	char* d = (char*)dst;
	char* s = (char*)src;
	if (dst < src) {
		while (size--) {
			*d++ = *s++;
		}
	} else {
		d += size - 1;
		s += size - 1;
		while (size--) {
			*d-- = *s--;
		}
	}
}

static void queue_grow(Queue* q) {
	int new_capacity = q->capacity << 1;
	char* new_p_elem = (char*)malloc(new_capacity * q->typesize);
	assert(new_p_elem != NULL);
	char* divide = q->p_elem + q->front * q->typesize;
	int lSize = divide - q->p_elem;
	int rSize = q->capacity * q->typesize - lSize;
	my_memcpy(new_p_elem, divide, rSize);
	my_memcpy(new_p_elem + rSize, q->p_elem, lSize);
	q->front = 0;
	q->rear = q->capacity;
	q->capacity = new_capacity;
	free(q->p_elem);
	q->p_elem = new_p_elem;
}

void queue_init(Queue* q, int n) {
	q->p_elem = (char*)malloc(DEFAULT_CAPACITY * n);
	assert(q->p_elem != NULL);
	q->capacity = DEFAULT_CAPACITY;
	q->size = 0;
	q->typesize = n;
	q->front = 0;
	q->rear = 0;
}

int queue_empty(Queue* q) {
	return !(q->size);
}

void queue_enque(Queue* q, void* src) {
	if (q->size == q->capacity) {
		queue_grow(q);
	}
	my_memcpy(q->p_elem + q->rear * q->typesize, src, q->typesize);
	q->size++;
	q->rear = (q->rear + 1) % q->capacity;
}

void queue_front(Queue* q, void* dst) {
	if (q->size != 0) {
		my_memcpy(dst, q->p_elem + q->front * q->typesize, q->typesize);
	}
}

void queue_deque(Queue* q, void* dst) {
	if (q->size != 0) {
		my_memcpy(dst, q->p_elem + q->front * q->typesize, q->typesize);
		q->size--;
		q->front = (q->front + 1) % q->capacity;
	}
}

void queue_destroy(Queue* q) {
	free(q->p_elem);
}