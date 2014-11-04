
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
int main(int argc, const char *argv[]) {
    /* List
     */
    llist   mlist = NULL;


    /* Open dictionary file
     */
    mlist = openDictfile(argv[1]);


    /* Display the results
     */
    display(mlist);

    return 0;
}
