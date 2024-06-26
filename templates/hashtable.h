#ifndef {TValue}_HASH_TABLE_H
#define {TValue}_HASH_TABLE_H

#ifndef ARRAYSIZE
#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif  // !ARRAYSIZE(a)

typedef bool ({TValue}_CompareFn)(const {TValue}, const {TValue});

typedef size_t ({TValue}_HashFn)({TKey}_{TValue}_Pair key, size_t size);

typedef struct {TKey}_{TValue}_Pair {
    {TKey} key;
    {TValue} value;
    struct {TValue}_Entry* next;
} {TValue}_Entry;

typedef struct {TValue}_HashTable {
    {TValue}_Entry* entries;
    size_t size;
} HashTable;


{TValue}_HashTable {TValue}_CreateHashTable(size_t size);
void {TValue}_Insert({TValue}_HashTable* table, {TKey} key, {TValue} value);
{TValue} {TValue}_Retrieve({TValue}_HashTable* table, {TKey} key);
void {TValue}_Remove({TValue}_HashTable* table, {TKey} key);

#endif // !{type}_HASH_TABLE_H