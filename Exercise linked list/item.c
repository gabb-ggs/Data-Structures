#include "item.h"

#include <stdlib.h>
#include <stdio.h>

struct Item{
    float price;
    char *name;
    int sku;
};

Item *newItem(char *name, int sku, float price){
    Item *tempItem = (Item *) calloc (1, sizeof(Item));
    setPrice(tempItem, price);
    setName(tempItem, name);
    setSku(tempItem, sku);
    return tempItem;
}

float getPrice(Item *i){
    return i->price;
} // get price of item

char *getName(Item *i){
    return i->name;
} // return char pointer of name

int getSku(Item *i){
    return i->sku;
} //return item sku

void setPrice(Item *i, float price){
    i->price = price;
} //if need to change

void setName(Item *i, char *name){
    i->name = name;
} //if need to change
 
void setSku(Item *i, int sku){
    i->sku = sku;
} //if need to change

void destroyItem(Item *i){
    free(i->name);
    free(i);
}

void printItem(Item *i){
    printf("\n    Product:\n");
    printf("        Name: %s\n", getName(i));
    printf("        SKU: %d\n", getSku(i));
    printf("        Price: %.2f\n", getPrice(i));
}
