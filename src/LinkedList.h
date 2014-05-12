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
void ReleaseLinkedList(struct LinkedList *list);

void PrependLL(struct LinkedList *list, item_t item);
void RemoveLL(struct LinkedList *list, item_t item);



#endif			
