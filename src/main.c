
/**
 * @file    main.c
 * @author  Henri Buyse <a href="henri.buyse@gmail.com">henri.buyse@gmail.com</a>
 */

#include "wordcount.h"
#include "ufgets.h"


/**
 * @brief Primary program
 *
 * @return Error code
 */
int main(int argc, char const *argv[]) {
    /* List
     */
    llist   mlist = NULL;

    char* string = ufgets(stdin);

    printf("String : %s\n", string);

    mlist = compareElements(mlist, "Toto");
    mlist = compareElements(mlist, "Toto");
    mlist = compareElements(mlist, "Tata");
    mlist = compareElements(mlist, "Toti");
    mlist = compareElements(mlist, "Toto");


    display(mlist);

    if (string) {
        free(string);
    }

    return 0;
}
