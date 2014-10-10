#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT_STRING 100

int main(int argc, char const *argv[]) {

    char string1[LIMIT_STRING] = "Toto";
    char string2[LIMIT_STRING] = "Toto";

    if (strncmp(string1, string2, LIMIT_STRING) == 0) {
        printf("Equal.\n");
    }
    else {
        printf("Not equal.\n");
    }

    return 0;
}