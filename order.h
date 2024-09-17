#ifndef ORDER_H
#define ORDER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stock.h"
#include "user.h"
#include "common.h"



// Prototipos de funciones (usando Market * en lugar de struct Market *)
Order createOrder_buy(Market *market, Stock *stock, User *user);
Order createOrder_sell(Market *market, Stock *stock, User *user);

void printOrders(Market *market);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ORDER_H */
