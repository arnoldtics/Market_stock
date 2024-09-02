#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "user.h"
#include "stock.h"
#include "market.h"

int main(int argn, char **argv) {
    User *user;
    Stock *stock;
    Market *market;
    char code[8];
    int i, N, M;
    float memory_used;

    if (argn >= 4) {  // Verifica que se proporcionen dos argumentos adicionales
        // Leer N (número de usuarios)
        if (sscanf(argv[3], "%i", &N) != 1 || N <= 0) {
            printf("Error: Número de usuarios inválido.\n");
            return 1;
        }

        user = malloc(sizeof(User) * N);
        if (user == NULL) {
            printf("Error: No se pudo asignar memoria para usuarios.\n");
            return 1;
        }

        printf("Generating %i users.\n", N);
        for (i = 0; i < N; i++) {
            user[i] = newUser(i, 1000.00);
        }

        // Leer M (número de acciones)
        if (sscanf(argv[2], "%i", &M) != 1 || M <= 0) {
            printf("Error: Número de acciones inválido.\n");
            free(user);
            return 1;
        }

        stock = malloc(sizeof(Stock) * M);
        if (stock == NULL) {
            printf("Error: No se pudo asignar memoria para acciones.\n");
            free(user);
            return 1;
        }

        market = newMarket(argv[1], M, N);

        printf("Generating %i stocks.\n", M);
        for (i = 0; i < M; i++) {
            sprintf(code, "MEX%i", i);
            addStock(market, newStock(code, 100.0));
            //stock[i] = newStock(code, 100.0);
        }

        printf("Ready!\n");
        memory_used = (float)(sizeof(user[0]) * N + sizeof(stock[0]) * M) / 1e6;
        printf("Memory used: %f Mb \n", memory_used);

        //printMarket(market);


    } else {
        print_help();
    }

    free(user);
    free(stock);
    free(market);
    return 0;
}
