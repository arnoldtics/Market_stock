#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "help.h"
#include "user.h"
#include "stock.h"
#include "market.h"
#include "engine.h"
#include "order.h"
#include "common.h"

// NOTE: The user not update the price of the order after the first execution. We need to create a new function to ask to the user if wants to update price after each execution ends.

int main(int argn, char **argv){
  User *user;
  Stock *stock;
  Market *market;
  char code[8];
  int i,j,k,n,N,M,P;
  float memory_used;
  
  //printf("%i\n",argn);
  if (argn == 5){
    sscanf(argv[2],"%i", &M);
    sscanf(argv[3],"%i", &N);
    sscanf(argv[4],"%i", &P);
    market = newMarket(argv[1],M,N,P);
    
    //user = malloc(sizeof(User)*N);
    //stock = malloc(sizeof(Stock)*M);
    printf("%i\n",M);    
    printf("#Labolsa simulator ver 20241022_1902\n");
    printf("# GNU/GPL License\n");
    printf("# By: Victor De la Luz <vdelaluz@enesmorelia.unam.mx>\n");
    // Creating stocks
    printf("#Generating %i stock... ",M);
    for(i=0; i < M; i++){
      sprintf(code,"MEX%i",i);
      addStock(market,newStock(code,10.0,1000));      
      //stock[i] = newStock(code,100.0);
    }
    printf("#Ready!\n");
     
    printf("#Generating %i users... ",N);
    for(i=0; i < N; i++){
      addUser(market,newUser(i,2000.00));
    }
    printf("#Ready!\n");
     //printf("%s:%f\n",stock[0].code,stock[0].price);
    memory_used = (float)(sizeof(User)*N+sizeof(Stock)*M)/1e6; 
    printf("#Memory used: %f Mb \n",memory_used);
    //print_divergence(market);
    // create the OPIs of our model. We create a random asignator of OPIS for all the users.
    srand(time(NULL));
    k=0;
    printf("#Computing IOPs...\n");
    do{
      for(int i=0; i < market->index_user;i++){
	j = (int)randomValue(0.0, (float)market->index_stock);
	  n = (int)((market->users[i].money/market->stocks[j].price)*randomValue(0.0, 1.0));
	  //printf("INFO: n= %i\n",n);
	  if (n < 1) n = 1;
	  //printf("INFO1:%s\n",market->stocks[j].code);
	buy_OPI(&market->stocks[j],&market->users[i],n,market->stocks[j].price);
      }
      k++;

      //printMarket(market);
      
    }while(remain_stocks(*market) > 0);

    printf("#IOPs iterations: %i\n",k);
    //print_divergence(market);
    //printMarket(market);

    printf("#Running Montecarlo...\n");
    for(int i=0; i < 1000; i++){
      printf("#%i:",i);
      montecarlo(market);
      printJapaneseCandle(market);
      //printOrders(market);
      //printMarket(market);
      //print_divergence(market);
    }
    
    //printMarket(market);
    print_divergence(market);
    //free(user);
    //free(stock);
    closeMarket(market);
  }else{
    print_help();
  }
  return 0;
}