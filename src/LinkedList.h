#ifndef _LLIST_H_
#define _LLIST_H_
#include <stddef.h>

typedef void * item_t;

struct LinkedListNode
{
	item_t val;
	struct LinkedListNode *next;
};

struct LinkedList
{
	struct LinkedListNode *head;
};

struct LinkedList *CreateLinkedList(void);

void PrependLL(struct LinkedList *list, item_t item);

void ReturnLL(struct LinkedList *list, item_t item);

#endif			
