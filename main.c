
/**
 * @file    main.c
 * @author  Henri Buyse
 * @mail    henri.buyse@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @def LIMIT_STRING
 * Limit size of a string
 */
#define LIMIT_STRING 100


/**
 * @typedef     element
 * @brief       Redefinition of the elem structure
 */
typedef struct elem element;


/**
 * @struct      elem
 * @brief       Creation of an element that can store two types of data : a string and a number of occurrences.
 */
struct elem {
    char*   string;
    int     occur;
    struct elem *nxt;
};


/**
 * @typedef     llist
 * @brief       Creation of a linked list in order to stock the elements
 */
typedef element *llist;



llist addElement(llist list, char *string) {
    /* Creation of a new element
     */
    element *newElement = malloc(sizeof(element));

    /* Allocating the size of the string
     * Copying the new string and the occurrence
     */
    newElement->string = malloc(sizeof(string));
    strcpy(newElement->string, string);
    newElement->occur = 1;

    /* Assigning the address of the next element to the element
     */
    newElement->nxt = list;

    /* Returning the new list (pointer on the first element)
     */
    return newElement;
}


void display(llist list) {
    element *tmp = list;

    /* While we are not at the end of the list
     */
    while (tmp != NULL) {
        printf("%d \t %s \n", tmp->occur, tmp->string);

        /* Going forward
         */
        tmp = tmp->nxt;
    }
}

/**
 * @function main
 * @brief Primary program
 *
 * @return Error code
 */
int main(int argc, char const *argv[]) {

    // char    string1[LIMIT_STRING] = "Toto";
    // char    string2[LIMIT_STRING] = "Toto";

    // if (strncmp(string1, string2, LIMIT_STRING) == 0) {
    //     printf("Equal.\n");
    // }
    // else {
    //     printf("Not equal.\n");
    // }

    llist mlist = NULL;

    mlist = addElement(mlist, "Toto");
    mlist = addElement(mlist, "Tata");

    display(mlist);

    return 0;
}
