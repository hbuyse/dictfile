
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
        printf("%d \t %s", tmp->occur, tmp->string);

        /* Going forward
         */
        tmp = tmp->nxt;
    }

    int     total = totalWords(list);

    printf("%d \t total words\n", total);
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



llist openDictfile(const char *firstArg) {
    /* Temporary list
     */
    llist   tmp = NULL;

    /* File pointer
     */
    FILE   *fp = NULL;

    /* Get the words
     */
    char   *str = NULL;
    char   *p = NULL;

    if (strcmp(dictfile, firstArg) == 0) {
#ifdef GETLINE
        char   *line = NULL;
        size_t  len = 0;
        ssize_t read;

        fp = fopen(dictfile, "r");
        if (fp == NULL)
            exit(EXIT_FAILURE);

        while ((read = getline(&line, &len, fp)) != -1) {
            /* Check if it begins with '#' or a newline
             */
            if (line[0] != '#' && line[0] != '\n') {
                line[sizeof(line) - 1] = '\0';
                printf("%zu\n", len);
                tmp = compareElements(tmp, line);
            }
        }

        if (line)
            free(line);
        fclose(fp);
#elif FGETS
        fp = fopen(dictfile, "r");
        char    line[LIMIT_STRING];

        while (fgets(line, sizeof(line), fp)) {
            /* Check if it begins with '#' or a new line
             */
            if (line[0] != '#' && line[0] != '\n') {
                tmp = compareElements(tmp, line);
            }
        }
        fclose(fp);
#endif
    }
    else {
        /* While we are not at the end of the string tokened,
           we compare every word.
         */
        str = ufgets(stdin);
        p = strtok(str, " ");
        for (int i = 0; p != NULL; i++) {
            tmp = compareElements(tmp, p);
            p = strtok(NULL, " ");
        }

        /* Free the string
         */
        if (str) {
            free(str);
        }
    }

    return tmp;
}
