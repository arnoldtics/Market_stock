#ifndef ORDER_H
#define ORDER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stock.h"
#include "user.h"

// Declaración adelantada de la estructura Market
struct Market;

typedef struct {
    Stock *stock;
    User *user;
    int n_actions; // Número de acciones en la transacción
    int typeOrder; // 0: sell, 1: buy
    float ask;
    float bid;
} Order;

// Prototipos de funciones (usando Market * en lugar de struct Market *)
int createOrder_buy(Market *market, Stock *stock, User *user, int n_actions, float bid);
int createOrder_sell(Market *market, Stock *stock, User *user, int n_actions, float ask);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ORDER_H */
