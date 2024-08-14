#ifndef LINKED_LIST___H
#define LINKED_LIST___H

typedef struct LinkedListNode {
	void *data;
	struct LinkedListNode *next;
	struct LinkedListNode *previous;
} LinkedListNode;

typedef struct LinkedList {
	int size;
	LinkedListNode *head;
	LinkedListNode *lastNode;
} LinkedList;

LinkedList *createLinkedList();

// Pushes a new object onto the linked list. Will copy the data of what the
// pointer points to.
void push(LinkedList *list, void *data, size_t dataSize);

void removeLast(LinkedList *list);

void *getItem(LinkedList *list, int index);

void destroyList(LinkedList *list);

void printLinkedList(LinkedList *list, void (*fptr)(void *));

#endif

