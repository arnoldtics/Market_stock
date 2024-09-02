#include <stdio.h>
#include <stdlib.h>
#include "help.h"
#include "user.h"
#include "stock.h"

int main(int argn, char **argv) {
    User *user;
    Stock stock[1000];
    char code[8];
    int i, N, M;

    if (argn >= 3) {  // Verifica que se proporcionen dos argumentos adicionales
        printf("La bolsa simulacro ver 20240828_1056\n");
        
        // Leer N (número de usuarios)
        if (sscanf(argv[1], "%i", &N) != 1 || N <= 0) {
            printf("Error: Número de usuarios inválido.\n");
            return 1;
        }

        user = malloc(sizeof(User) * N);
        if (user == NULL) {
            printf("Error: No se pudo asignar memoria para usuarios.\n");
            return 1;
        }

        printf("Generating %i users.\n", N);
        for(i = 0; i < N; i++) {
            user[i] = newUser(i, 1000.00);
        }
        printf("Memory used: %lu Kb\n", sizeof(user[0]) * N / 1000);

        // Leer M (número de acciones)
        if (sscanf(argv[2], "%i", &M) != 1 || M <= 0) {
            printf("Error: Número de acciones inválido.\n");
            free(user);
            return 1;
        }

        printf("Generating %i stocks.\n", M);
        for (i = 0; i < M; i++) {
            sprintf(code, "MEX%i", i);
            stock[i] = newStock(code, 100.0);
        }
        printf("Ready!\n");
        printf("Memory used: %lu Kb\n", (sizeof(stock[0]) * M / 1000) + (sizeof(user[0]) * N / 1000));
        //printf("%s:%f\n", stock[0].code, stock[0].price);

    } else {
        print_help();
    }

    free(user);
    return 0;
}
