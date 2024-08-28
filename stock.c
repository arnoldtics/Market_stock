#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"

Stock newStock(char code[], float price){
    Stock stock;
    stock.price = price;
    strcpy(stock.code, code);
    return stock;
}