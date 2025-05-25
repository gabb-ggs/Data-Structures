#ifndef linked_list_h
#define linked_list_h

typedef struct linkedList linkedList;
typedef struct Cell Cell;
typedef void (*freeFunction)(void *itemPointer);
typedef void (*genericPrintFunction)(void *itemPointer);
typedef int (*genericGetId)(void *itemPointer);

linkedList *newList();

void addElement(linkedList *l, void *item);

void removeElement(linkedList *l, int code, genericGetId genGetId);

linkedList *createList();

void *returnElement(linkedList *l, int code, genericGetId genGetId);

void freeList(linkedList *l);

void freeItemsList(linkedList *l, freeFunction freeF);

void printAllItems(linkedList *l, genericPrintFunction genericPrint);

#endif