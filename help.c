#include <stdio.h>
#include <stdlib.h>
#include "help.h"

void print_help(){
    printf("Error: Missing arguments.\n");
    printf("Three argument are required:\n");
    printf("Example: ./montecarlo.exe <name> <stocks> <users> <orders>\n");
}