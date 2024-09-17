#include "order.h"
#include "market.h"
#include "user.h"
#include "stock.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

double randomValue(double a, double b){
    //Generar un numero pseudoaleatorio entre 0 y 1
    double rvalue = rand() / (double) RAND_MAX;
    //Escalar el valor en el rango [-0.05, 0.05]
    return b + rvalue * (a - b);

}

Order createOrder_buy(Market *market, Stock *stock, User *user) {
    Order order;
    float risk; 
    if (market->index_order < market->norders){
        risk = (float) randomValue(-0.05, 0.02);
        order.stock = stock;
        order.user = user;
        order.typeOrder = 1;
        order.bid = stock->price*(1.0+risk);
        order.n_actions = (int)((user->money/order.bid)*randomValue(0.0, 1.0));
        if (order.n_actions < 1){ order.n_actions = 1;}
        user->money -= order.n_actions * order.bid;
        user->money_in_orders += order.n_actions * order.bid;
        market->orders[market->index_order] = order;
        market->index_order++;
    } else { 
        printf("Waring: Not enough memory to create order.\n");
        order.typeOrder = -1;
        }
    return order;
}

Order createOrder_sell(Market *market, Stock *stock, User *user) {
    Order order;
    return order; 
}

void printOrders(Market *market){
  for (int i=0; i < market->index_order; i++){
    printf("%i,%i\n",i,market->orders[i].n_actions);
  }
}