#ifndef item_h
#define item_h

typedef struct Item Item;

Item *newItem(char *name, int sku, float price);

float getPrice(Item *i); // get price of item

char *getName(Item *i); // return char pointer of name

int getSku(Item *i); //return item sku

void setPrice(Item *i, float price); //if need to change

void setName(Item *i, char *name); //if need to change
 
void setSku(Item *i, int sku); //if need to change

void destroyItem(Item *i);

void printItem(Item*i);

#endif