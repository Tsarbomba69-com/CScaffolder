#include "{type}_arraylist.h"

// WARNING: You can implement your own memory management API. Using libc API as default---------

{type}* {type}_AllocateContext(size_t size)
{
	assert(size > 0);
	return ({type}*)malloc(size);
}

void {type}_FreeContext({type}* obj_ptr) {
	free(obj_ptr);
}

{type}* {type}_ReallocateContext({type}* oldptr, size_t oldptr_size, size_t size)
{
	assert(size > oldptr_size);
	return realloc(oldptr, oldptr_size, size);
}

// -----------------------------------------------------------------------------------------------

{type}_ArrayList {type}_CreateArrayList(size_t capacity)
{
	{type}_ArrayList list = { 0 };
	list.capacity = capacity;
	{type}_AllocateElementes(&list);
	return list;
}

{type}_ArrayList* {type}_AllocateArrayList(size_t capacity) {
	{type}_ArrayList* list = {type}_AllocateContext(sizeof({type}_ArrayList));
	if (list == NULL) {
		fprintf(stderr, "ERROR: Could not allocate memory for \"{type}\" array list");
		return NULL;
	}
	list->capacity = capacity;
	{type}_AllocateElementes(list);
	return list;
}

void {type}_AllocateElementes({type}_ArrayList* list)
{
	list->elements = {type}_AllocateContext(list->capacity * sizeof({type}));
	if (list->elements == NULL) {
		fprintf(stderr, "ERROR: Could not allocate memory for \"{type}\" array list elements");
	}
	list->size = 0;
}

{type} {type}_Pop({type}_ArrayList* list) {
	if (list->size == 0) {
		return NULL; // ArrayList is empty, return NULL
	}

	{type} element = list->elements[list->size - 1]; // Get the last element
	list->size--; // Decrement the size
	return element; // Return the last element
}

void {type}_Push({type}_ArrayList* list, {type} value)
{
	if (list->size == list->capacity) {
		size_t cap = list->capacity * 2;
		{type}* elements = {type}_ReallocateContext(list->elements, list->size * sizeof({type}), cap * sizeof({type}));
		if (elements == NULL) {
			fprintf(stderr, "ERROR: Failed to resize \"{type}\" array list\n");
			return;
		}
		list->elements = elements;
		list->capacity = cap;
	}
	list->elements[list->size++] = value;
}

bool {type}_Any({type}_ArrayList const *list, {type} const el, {type}_CompareFn predicate)
{
	for (size_t i = 0; i < list->size; i++) {
	    {type} curr = {type}_Get(list, i);
		if (predicate(curr, el)) {
			return true;
		}
	}
	return false;
}

void {type}_ForEach({type}_ArrayList const *list, {type}_Action callback)
{
	for (size_t i = 0; i < list->size; i++)
	{
		{type} element = list->elements[i];
		if (element != NULL) callback(element);
	}
}

