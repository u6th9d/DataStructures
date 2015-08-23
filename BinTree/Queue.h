/*********************************************
*
*Author: u6th9d E-mail: u6th9d@outlook.com
*Copyright (c) 2015-08-18 All rights reserved
*
**********************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#define DEFAULT_CAPACITY 8

typedef struct queue {
	char* p_elem;
	int size, capacity, typesize, front, rear;
}Queue;

void queue_init(Queue* q, int typesize);

int queue_empty(Queue* q);

void queue_enque(Queue* q, void* src);

void queue_front(Queue* q, void* dst);

void queue_deque(Queue* q, void* dst);

void queue_destroy(Queue* q);

#endif