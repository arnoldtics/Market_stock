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

    srand(time(NULL));

    for(int i; i < market->index_stock; i++){
        price = market->stocks[i].price;
        for(int j; j < market->index_user; j++){
            //if (price <= market->users[j].money){
                //the user has enough money to make a transaction
                
                if (askOrderBuy(market->users[j], market->stocks[i])){
                    //r = rand();
                    //if (r%2 == 0){
                    // run the market
                    n_actions = 0; bid = 0.0;
                    createOrder_buy(&market, &market->stocks[i], &market->users[j]);
                } else{
                    // pass
                }
            //}
        }
    }
    return 1;
}

int printJapaneseCandle(Market *market){
    return 1;
}