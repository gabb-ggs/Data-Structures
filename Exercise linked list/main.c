#include "linked_list.h"
#include "item.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_NAME_SIZE 100

/* FEATURES
    -- Creation
    -- Insertion
    -- Removes
    -- Print
    -- Free

*/
char *catchString(){
    char *tempName;
    tempName = (char *) calloc(MAX_NAME_SIZE, sizeof(char));
    scanf("%s", tempName);
    return tempName; 
}
Item *userEntryItem(){
    char *tempName;
    float tempPrice;
    int tempSku;
    printf("\n-- Creating new item-- \n\n");
    printf("    Please insert product name: ");
    tempName = catchString();
    printf("\n    Please insert product price: ");
    scanf("%f", &tempPrice);
    printf("\n    Please insert product SKU: ");
    scanf("%d", &tempSku);
    return newItem(tempName, tempSku, tempPrice);
}

int main(){
    int n, i;
    printf("Please insert how many products to insert:");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        Item * temp = userEntryItem();
        printItem(temp);
    }
    return 0;
}