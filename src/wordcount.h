
/**
 * @file    wordcount.h
 * @author  Henri Buyse <a href="henri.buyse@gmail.com">henri.buyse@gmail.com</a>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ufgets.h"


/**
 * @def         LIMIT_STRING
 * @brief       Limit size of a string
 */
#define LIMIT_STRING 50


static const char dictfile[9] = "dictfile\0";

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
    char   *string;             ///< String stored
    int     occur;              ///< Number of occurrences
    struct elem *nxt;           ///< Next element
};

/**
 * @typedef     llist
 * @brief       Creation of a linked list in order to stock the elements
 */
typedef element *llist;


/**
 * @brief Add a new element to the list
 *
 * @param list Old list
 * @param string The string for the new element
 *
 * @return New list
 */
llist   addElement(llist list, char *string);


/**
 * @brief       Display the list using the given format
 *
 * @param       list List to display
 */
void    display(llist list);


/**
 * @brief Compare the string given with all the strings of the linked list
 *
 * @param list Old list
 * @param string String to compare
 *
 * @return New List
 */
llist   compareElements(llist list, char *string);

/**
 * @brief Calculate the number total of words
 *
 * @param list Linked list of words
 *
 * @return The total number of words
 */
int     totalWords(llist list);


llist   openDictfile(const char *firstArg);
