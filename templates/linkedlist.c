#include "{type}_linkedlist.h"

{type}_LinkedList {type}_CreateLinkedList() {
    {type}_LinkedList list = { 0 };
	list.size = 0;
	list.head = NULL;
	return list;
}

{type}_LinkedList* {type}_AllocateLinkedList() {
	{type}_LinkedList* list = malloc(sizeof({type}_LinkedList));
	if (list == NULL) {
		fprintf(stderr, "ERROR: Could not allocate memory for \"{type}\" linked list");
		return NULL;
	}
	list->size = 0;
    list->head = NULL;
	return list;
}

{type}_Node* {type}_CreateNode({type} data) {
    {type}_Node* newNode = malloc(sizeof({type}_Node));
    if (newNode == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for \"{type}\" node\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void {type}_AddFirst({type}_LinkedList* list, {type} data) {
    {type}_Node* newNode = {type}_CreateNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void {type}_AddLast({type}_LinkedList *list, {type} *data) {
    {type}_Node *newNode = {type}_CreateNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    {type}_Node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    list->size++;
}

{type} {type}_Pop({type}_LinkedList* list) {
    if (list->head == NULL) {
        return NULL;
    }

    {type} value = list->head->data;
    {type}_Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    return value;
}