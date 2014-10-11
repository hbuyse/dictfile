
/**
 * @file    ufgets.c
 * @author  Brandon Mills <a href="mills.brandont@gmail.com">mills.brandont@gmail.com</a>
 */

#include <stdio.h>
#include <stdlib.h>



char   *ufgets(FILE * stream) {
    unsigned int maxlen = 128, size = 128;
    char   *buffer = (char *) malloc(maxlen);

    if (buffer != NULL) {       /* NULL if malloc() fails */
        int     ch = EOF;
        int     pos = 0;

        /* Read input one character at a time, resizing the buffer as necessary */
        while ((ch = fgetc(stream)) != '\n' && ch != EOF && !feof(stream)) {
            buffer[pos++] = ch;
            if (pos == size) {  /* Next character to be inserted needs more memory */
                size = pos + maxlen;
                buffer = (char *) realloc(buffer, size);
            }
        }
        buffer[pos] = '\0';     /* Null-terminate the completed string */
    }
    return buffer;
}
