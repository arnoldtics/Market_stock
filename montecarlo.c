#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "user.h"
#include "stock.h"

int main(int argn, char **argv){
    User *user;
    Stock stock[1000];
    char code[8];
    int i, N, M;
    if (argn >= 2){
        printf("La bolsa simulacro ver 20240828_1056\n");
        

        sscanf(argv[1], "%i", &N);
        user = malloc(sizeof(User)*N);
        printf("Generating %i users.\n", N);
        for(i=0; i<N;i++){
            user[i] = newUser(i, 1000.00);
        }
        printf("Memory used: %lu Kb\n", sizeof(user[0])*N/1000);


        sscanf(argv[2], "%i", &M);
        printf("Generating %i stocks.\n");
        for (i=0; i<M; i++){
            sprintf(code, "MEX%i", i);
            stock[i] = newStock(code, 100.0);
        }
        printf("Ready!\n");
        printf("Memory used: %lu Kb\n", (sizeof(stock[0])*M/1000000) + (sizeof(user[0])*N/1000000));
        //printf("%s:%f\n", stock[0].code, stock[0].price);

    } else {
        print_help();
    }
    free(user);
    return 0;
}