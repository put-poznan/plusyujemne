#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>

struct LinkedList *CreateLinkedList(void)
{
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	list->head = NULL;
	return list;
}

void PrependLL(struct LinkedList *list, item_t item)
{
	assert(list != NULL);
	struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
	node->val = item;
	node->next = list->head;
	list->head = node;
}


void RemoveLL(struct LinkedList *list, item_t item)
{
	assert(list != NULL);
	assert(item != NULL);
	struct LinkedListNode *todel;

	if(list->head == NULL)
		return;

	if(list->head->next == NULL)
	{
		//list contains single element
		free(list->head->next);
		list->head = NULL;
		return;
	}

	struct LinkedListNode *iter = list->head;
	while(iter->next != NULL)
	{
		if(iter->next->val == item)
		{
			todel = iter->next;
			iter->next = iter->next->next;
			free(todel);
			return;
		}
		iter = iter->next;
	}

}

void ReleaseLinkedList(struct LinkedList *list)
{
	struct LinkedListNode *next;
	assert(list != NULL);

	if (list->head == NULL)
		return;


	next = list->head->next;
	free(list->head);
	list->head = next;
	ReleaseLinkedList(list);
}
