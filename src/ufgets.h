
/**
 * @file    ufgets.h
 * @author  Brandon Mills <a href="mills.brandont@gmail.com">mills.brandont@gmail.com</a>
 */

#include <stdio.h>

/**
 * @param stream    Stream read
 *
 * @brief           Unlimited fgets
 * @details         Similar to fgets(), but handles automatic reallocation of the buffer.
 *                  Only parameter is the input stream.
 *                  Return value is a string. Don't forget to free it.
 */
char   *ufgets(FILE * stream);
