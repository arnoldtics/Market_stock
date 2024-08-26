#include <stdio.h>
#include <stdlib.h>
#include "help.h"

int main(int argn, char **argv){
    if (argn >= 2){
        printf("ok %s\n", argv[1]);
    } else {
        print_help();
    }
    return 0;
}