#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#ifndef {type}_ARRAYLIST_H
#define {type}_ARRAYLIST_H

#ifndef ARRAYSIZE(a)
#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif  // !ARRAYSIZE(a)

typedef struct {
	{type}* elements;
	size_t size;
	size_t capacity;
} {type}_ArrayList;

typedef void (*Action)({type});

typedef bool (*CompareFn)(const {type}, const {type});

// Memory operations ------------------------------------------

{type}* {type}_AllocateContext(size_t size);

{type}* {type}_ReallocateContext({type}* oldptr, size_t oldptr_size, size_t size);

void {type}_AllocateElementes({type}_ArrayList* list);

// ------------------------------------------------------------

bool {type}_ArrayListAny({type}_ArrayList*, {type}, CompareFn);

{type}_ArrayList {type}_CreateArrayList(size_t capacity);
// Creates an array list on the heap
{type}_ArrayList* {type}_AllocateArrayList(size_t capacity);
// Pushes an element to the end of the array list
void {type}_ArrayListPush({type}_ArrayList* list, {type} value);
// Get the last element and remove it
{type} {type}_ArrayListPop({type}_ArrayList* list);
// Get the element stored at the index. Returns NULL if index is out-of-bounds
inline {type} {type}_ArrayListGet({type}_ArrayList* arrayList, size_t index)
{
	return index < arrayList->size ? arrayList->elements[index] : NULL;
}
// Iterate the array list and apply the callback for each element
void {type}_ArrayListForEach({type}_ArrayList* list, Action callback);
#endif // !{type}_ARRAYLIST_H