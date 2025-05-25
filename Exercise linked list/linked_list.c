#include "linked_list.h"
#include <stddef.h>
#include <stdlib.h>

struct Cell{
    void *item;
    Cell *next;
};

struct linkedList{
    Cell *first;
    Cell *last;
};

Cell *newCell(){
    return (Cell*) calloc(1, sizeof(Cell));
}
linkedList *newList(){
    linkedList *tempList = (linkedList*) calloc(1, sizeof(linkedList));
    tempList->first = NULL;
    tempList->last = NULL;
    return tempList;
}

void addElement(linkedList *l, void *item){
    Cell *tempCell = newCell();
    tempCell->item = item;
    if(l->first == NULL){
        l->first = tempCell;
        l->last = l->first;
        tempCell->next = NULL;
    } else {
        l->last->next = tempCell;
        l->last = tempCell;
        tempCell->next = NULL; 
    }
}

void *returnElement(linkedList *l, int code, genericGetId genGetId){
    Cell *tempCell;
    tempCell = l->first;
    while(tempCell != NULL){
        if(genGetId(tempCell->item) == code){
            return (void*)tempCell->item;
        }
        tempCell = tempCell->next;
    }
    return NULL;
}

void freeList(linkedList *l){
    Cell *tempCell;
    tempCell = l->first;
    Cell *auxCell;
    while(tempCell != NULL){
        auxCell = tempCell->next;
        free(tempCell);
        tempCell = auxCell;
    }
}

void freeItemsList(linkedList *l, freeFunction freeF){
    Cell *tempCell;
    tempCell = l->first;
    Cell *auxCell;
    while(tempCell != NULL){
        auxCell = tempCell->next;
        freeF(tempCell->item);
        free(tempCell);
        tempCell = auxCell;
    }
}

void printAllItems(linkedList *l, genericPrintFunction genericPrint){
    Cell *tempCell;
    tempCell = l->first;
    while(tempCell != NULL){
        genericPrint(tempCell->item);
        tempCell = tempCell->next;
    }
}

void removeElement(linkedList *l, int code, genericGetId genGetId){
    Cell *tempCell;
    tempCell = l->first;
    Cell *auxCell = NULL;
    while(tempCell != NULL){
        if(genGetId(tempCell->item) == code){
            if(tempCell == l->first && tempCell == l->last){
                free(tempCell);
                l->first = NULL;
                l->last = NULL;
                break;
            } else if(tempCell == l->last){
                l->last = auxCell;
                l->last->next = NULL;
                free(tempCell);
                break;
            } else if(tempCell == l->first){
                l->first = tempCell->next;
                free(tempCell);
                break;
            } else {
                auxCell->next = tempCell->next;
                free(tempCell);
                break;
            }
        }
        auxCell = tempCell;
        tempCell = tempCell->next;
    }
}

