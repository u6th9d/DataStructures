#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void queue_test1() {
	Queue queue;
	queue_init(&queue, sizeof(int));
	
	for (int i = 0; i < 10; i++) {
		queue_enque(&queue, &i);
	}

	for (int i = 0; i < 5; i++) {
		int item;
		queue_deque(&queue, &item);
		printf("%d ", item);
	}
	putchar('\n');

	for (int i = 15; i < 30; i++) {
		queue_enque(&queue, &i);
	}

	for (int i = 0; i < 15; i++) {
		int item;
		queue_deque(&queue, &item);
		printf("%d ", item);
	}
	putchar('\n');

	queue_destroy(&queue);
}

//int main() {
//	queue_test1();
//
//	system("pause");
//}