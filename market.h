#ifndef MARKET_H
#define MARKET_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "stock.h"
#include "user.h"

typedef struct{
    char name[8];
    int nstocks; // max number of stocks
    int nusers; // max number of users
    int index_stock; // total of stock
    int index_user; // total of user
    Stock *stocks; 
    User *users;
} Market;

Market *newMarket(char name[], int nstocks, int nusers);

int addStock(Market *market, Stock stock);
int addUser(Market *market, User user);

void printMarket(Market *market);

int closeMarket(Market *market);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MARKET_H */