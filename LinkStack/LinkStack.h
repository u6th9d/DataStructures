#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef void LinkStack;

typedef struct _LinkStackNode {
	struct _LinkStackNode* next;
}LinkStackNode;

LinkStack* LinkStack_Create();

int LinkStack_Destroy(LinkStack* stack);

int LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* item);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

#endif