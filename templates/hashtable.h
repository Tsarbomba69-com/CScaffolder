#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#ifndef {TValue}_HASH_TABLE_H
#define {TValue}_HASH_TABLE_H

#ifndef ARRAYSIZE
#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif  // !ARRAYSIZE(a)

typedef bool ({TValue}_CompareFn)(const {TValue}, const {TValue});

typedef struct {TKey}_{TValue}_Pair {
    {TKey} key;
    {TValue} value;
    struct {TKey}_{TValue}_Pair* next;
} {TKey}_{TValue}_Pair;

typedef struct {TValue}_HashTable {
    size_t capacity;
    size_t size;
    {TKey}_{TValue}_Pair* buckets;
} {TValue}_HashTable;

//
{TValue}_HashTable {TValue}_CreateHashTable(size_t capacity);
// Hash function for the key-value pair
inline size_t {TValue}_Hash({TKey} key, size_t size) {
    return (size_t)key % size;
}
// Heap allocate the dynamic array within the table struct
void {TValue}_AllocateElementes({TValue}_HashTable* table);
// Insert a key-value pair into the hash table
void {TValue}_Insert({TValue}_HashTable* table, {TKey} key, {TValue} value);
//
{TValue} {TValue}_Retrieve({TValue}_HashTable* table, {TKey} key);
//
void {TValue}_Remove({TValue}_HashTable* table, {TKey} key);

#endif // !{TValue}_HASH_TABLE_H