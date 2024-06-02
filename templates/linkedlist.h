#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#ifndef {type}_LINKEDLIST_H
#define {type}_LINKEDLIST_H

typedef void (*{type}_Action)({type});

typedef bool (*{type}_CompareFn)(const {type}, const {type});

// node structure
typedef struct {
    {type} data;
    struct {type}_Node* next;
} {type}_Node;

typedef struct {
    {type}_Node* head;
    size_t size;
} {type}_LinkedList;

// Stack allocated linkedlist constructor
{type}_LinkedList {type}_CreateLinkedList();
// Heap allocated linkedlist constructor
{type}_LinkedList* {type}_AllocateLinkedList();
// Heap allocated node constructor
{type}_Node* {type}_CreateNode({type} data);
// Adds an element at the beginning of the list
void {type}_AddFirst({type}_LinkedList* list, {type} data);
// Traverse linked list
void {type}_ForEach({type}_LinkedList* list,  {type}_Action callback);
// Get the last element and remove it
{type} {type}_Pop({type}_LinkedList* list);
#endif // !{type}_LINKEDLIST_H