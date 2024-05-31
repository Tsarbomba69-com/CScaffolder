

#define ARRAYSIZE(a) (sizeof(a)/sizeof((a)[0]))

typedef struct {
	{type} elements;
	size_t size;
	size_t capacity;
} ArrayList;

typedef void (*Action)({type});

typedef bool (*CompareFn)(const {type}, const {type});

bool Any(ArrayList*, void*, CompareFn);

void AllocateElementes(ArrayList* list);

ArrayList CreateArrayList(size_t capacity);
// Creates an array list on the heap
ArrayList* AllocateArrayList(size_t capacity);
// Pushes an element to the end of the array list
void {type}_Push(ArrayList* list, {type} value);
// Get the last element and remove it
void* {type}_Pop(ArrayList* list);
// Get the element stored at the index. Returns NULL if index is out-of-bounds
inline void* {type}_Get(ArrayList* arrayList, size_t index)
{
	return index < arrayList->size ? arrayList->elements[index] : NULL;
}
// Iterate the array list and apply the callback for each element
void ArrayListForEach(ArrayList* list, Action callback);