#ifndef ORDER_H
#define ORDER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stock.h"
#include "user.h"
#include "market.h"

// Declaración adelantada de la estructura Market
//typedef struct Market;

typedef struct {
    Stock *stock;
    User *user;
    int n_actions; // Número de acciones en la transacción
    int typeOrder; // 0: sell, 1: buy, -1:not enough memory
    float ask;
    float bid;
} Order;

// Prototipos de funciones (usando Market * en lugar de struct Market *)
Order createOrder_buy(Market *market, Stock *stock, User *user);
Order createOrder_sell(Market *market, Stock *stock, User *user);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ORDER_H */
