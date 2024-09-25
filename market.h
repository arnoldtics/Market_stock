#ifndef MARKET_H
#define MARKET_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stock.h"
#include "user.h"
#include "common.h"



Market *newMarket(char name[], int nstocks, int nusers, int norders);

int addStock(Market *market, Stock stock);
int addUser(Market *market, User user);

void printMarket(Market *market);

int closeMarket(Market *market);

int buy_OPI(Stock *stock, User *user, int nstocks, float value);

int remain_stocks(Market market);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MARKET_H */