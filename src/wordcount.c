
/**
 * @file    wordcount.c
 * @author  Henri Buyse <a href="henri.buyse@gmail.com">henri.buyse@gmail.com</a>
 */

#include "wordcount.h"



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

    int     total = totalWords(list);

    printf("%d \t total words \n", total);
}



llist compareElements(llist list, char *string) {
    element *tmp = list;

    /* While we are not at the end of the list.
     */
    while (tmp != NULL) {
        /* Check if the two strings are equal.
         */
        if (strcmp(tmp->string, string) == 0) {
            /* If it is, we add an occurrence.
               And we return the list with the additional occurrence.
             */
            tmp->occur++;
            return list;
        }

        tmp = tmp->nxt;
    }

    /* If the string not found
     */
    llist   newElement = addElement(list, string);

    return newElement;
}



int totalWords(llist list) {
    element *tmp = list;

    int     totalWords = 0;

    /* While we are not at the end of the list.
     */
    while (tmp != NULL) {
        totalWords += tmp->occur;
        tmp = tmp->nxt;
    }

    return totalWords;
}
