#ifndef USER_H
#define USER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stock.h"

typedef struct{
    int index;
    float money; // total money of the user
    float money_in_orders; //money compromised in orders
} User;

User newUser(int index, float money, float money_in_orders);

// ask to participete to buy action in stock
int askOrderBuy(User user, Stock stock);

int askOrderSell(User user, Stock stock);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* USER_H */