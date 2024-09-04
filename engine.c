#include "market.h"

int montecarlo(Market *market){
    float price;
    int r;
    srand(time(NULL));

    for(int i; i < market->index_stock; i++){
        price = market->stocks[i].price;
        for(int j; j < market->index_user; j++){
            if (price <= market->users[j].money){
                //the user has enough money to make a transaction
                r = rand();
                if (r%2 == 0){
                    // run the market
                    newOrderBuy(market->stocks[i], n, bid);
                } else{
                    // pass
                }
            }
        }
    }
    return 1;
}

int printJapaneseCandle(Market *market){
    return 1;
}