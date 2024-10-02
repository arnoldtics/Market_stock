#include "market.h"
#include "order.h"
#include "user.h"
#include <time.h>   // Para la función time()
#include <stddef.h> // Para NULL
#include <stdio.h>
#include <stdlib.h>

int montecarlo(Market *market){
    float price;
    int r;
    int n_actions;
    float ask,bid;
    int actual_stock;

    // Creating Buy/Sell orders
    printf("Creating orders.\n");

    srand(time(NULL));

    for(int i=0; i < market->index_stock; i++){
        price = market->stocks[i].price;
        for(int j=0; j < market->index_user; j++){
            //if (price <= market->users[j].money){
                //the user has enough money to make a transaction
                
                if (askOrderBuy(market->users[j], market->stocks[i])){
                    createOrder_buy(market, &market->stocks[i], &market->users[j]);
                } 
                
                if (askOrderSell(market->users[j], market->stocks[i])){
                    createOrder_sell(market, &market->stocks[i], &market->users[j]);
                }
            //}
        }
    }

    // Executing orders

    for (int i = 0; i < market->index_order_buy; i++){
        bid = market->orders_buy[i].bid;
        for (int j = 0; j < market->index_order_sell; j++){
            ask = market->orders_sell[j].ask;
            if (bid >= ask){
                n_actions = market->orders_buy[i].n_actions;
                if (market->orders_buy[i].n_actions > market->orders_sell[j].n_actions){
                    n_actions = market->orders_sell[j].n_actions;
                }
                // Update the n_actions in the order
                market->orders_buy[i].n_actions -= n_actions;
                // Update the money in order from the user i
                market->orders_buy[i].user->money_in_orders -= n_actions*bid;
                // Transfering money to seller
                market->orders_sell[j].user->money += n_actions*bid;
                // Delete the stock from the seller
                actual_stock = get(*market->orders_sell[j].user, market->orders_buy[i].stock->code);
                insert(market->orders_sell[j].user, market->orders_sell[i].stock[i].code, actual_stock - n_actions);
                // Transfer the stock to the buyer
                actual_stock = get(*market->orders_buy[i].user, market->orders_sell[j].stock->code);
                insert(market->orders_buy[i].user, market->orders_sell[j].stock[i].code, actual_stock + n_actions);
                // Update the price of the stock
                market->orders_buy[i].stock->price = (market->orders_buy[i].stock->price + bid) / 2.0;

            }
        }
    }

    printMarket(market);
    return 1;
}

int printJapaneseCandle(Market *market){
    return 1;
}