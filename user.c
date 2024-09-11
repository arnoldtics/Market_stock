#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "stock.h"

User newUser(int index, float money, float money_in_orders){
    User user;
    user.index = index;
    user.money = money;
    user.money_in_orders = money_in_orders;
    return user;
}

int askOrderBuy(User user, Stock stock){
    int r; r = rand();
    if ((r%2 == 0) && (user.money >= stock.price)){return 1;}
    else {return 0;}
}

int askOrderSell(User user, Stock stock);
