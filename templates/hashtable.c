#include "{TValue}_hashtable.h"

// WARNING: You can implement your own memory management API. Using libc API as default---------

{TValue}* {TValue}_AllocateContext(size_t size)
{
	assert(size > 0);
	return ({TValue}*)malloc(size);
}

void {TValue}_FreeContext({TValue}* obj_ptr) {
	free(obj_ptr);
}

{TValue}* {TValue}_ReallocateContext({TValue}* oldptr, size_t oldptr_size, size_t size)
{
	assert(size > oldptr_size);
	return realloc(oldptr, oldptr_size, size);
}

// -----------------------------------------------------------------------------------------------


{TValue}_HashTable {TValue}_CreateHashTable(size_t capacity) {
	{TValue}_HashTable table = { 0 };
	table.size = 0;
	{TValue}_AllocateElementes(&table);
	return table;
}

void {TValue}_AllocateElementes({TValue}_HashTable* table)
{
	table->buckets = {TValue}_AllocateContext(table->capacity * sizeof({TValue}));
	if (table->buckets == NULL) {
		fprintf(stderr, "ERROR: Could not allocate memory for \"{TValue}\" table buckets");
	}
	table->size = 0;
}

void {TValue}_Insert({TValue}_HashTable* table, {TKey} key, {TValue} value) {
    if (table->size >= table->capacity) {
        size_t cap = table->capacity * 2;
        {TKey}_{TValue}_Pair* buckets = {TValue}_ReallocateContext(table->buckets, table->size * sizeof({TValue}), cap * sizeof({TValue}));
        if (buckets == NULL) {
			fprintf(stderr, "ERROR: Failed to resize \"Symbol*\" buckets\n");
			return;
		}
		for (size_t i = 0; i < table->capacity; i++) {
            char_Symbol_Pair* current = &table->buckets[i];
            while (current != NULL) {
                {TKey}_{TValue}_Pair* next = current->next;
                size_t index = Symbol_Hash(current->key, cap);
                current->next = &buckets[index];
                buckets[index] = *current;
                current = next;
            }
        }
		table->buckets = buckets;
		table->capacity = cap;
    }

    size_t index = Symbol_Hash(key, table->capacity);
    {TKey}_{TValue}_Pair* pair = AllocateContext(sizeof({TKey}_{TValue}_Pair));
    pair->key = key;
    pair->value = value;
    pair->next = &table->buckets[index];
    table->buckets[index] = *pair;
    table->size++;
}