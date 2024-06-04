#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#ifndef {type}_ARRAYLIST_H
#define {type}_ARRAYLIST_H

#ifndef ARRAYSIZE
#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif  // !ARRAYSIZE(a)

typedef struct {
	{type}* elements;
	size_t size;
	size_t capacity;
} {type}_ArrayList;

typedef void (*{type}_Action)({type});

typedef bool (*{type}_CompareFn)(const {type}, const {type});

// Memory operations ------------------------------------------

// Custom defined memory allocation function
{type}* {type}_AllocateContext(size_t size);
// Custom defined memory reallocation function
{type}* {type}_ReallocateContext({type}* oldptr, size_t oldptr_size, size_t size);

// ------------------------------------------------------------

// Find any element within the array list that satisfy the predicate
bool {type}_Any({type}_ArrayList*, {type}, {type}_CompareFn);
// Stack allocated array list constructor
{type}_ArrayList {type}_CreateArrayList(size_t capacity);
// Heap allocated array list constructor
{type}_ArrayList* {type}_AllocateArrayList(size_t capacity);
// Heap allocate the dynamic array within the array list struct
void {type}_AllocateElementes({type}_ArrayList* list);
// Pushes an element to the end of the array list
void {type}_Push({type}_ArrayList* list, {type} value);
// Get the last element and remove it
{type} {type}_Pop({type}_ArrayList* list);
// Get the element stored at the index. Returns NULL if index is out-of-bounds
static inline {type} {type}_Get({type}_ArrayList const* arrayList, size_t index)
{
	return index < arrayList->size ? arrayList->elements[index] : NULL;
}
// Iterate the array list and apply the callback for each element
void {type}_ForEach({type}_ArrayList* list, {type}_Action callback);
#endif // !{type}_ARRAYLIST_H