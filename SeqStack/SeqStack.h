#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

typedef void SeqStack;

SeqStack* SeqStack_Create(int capacity);

int SeqStack_Destroy(SeqStack* stack);

int SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int SeqStack_Length(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif