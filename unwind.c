#include <stdio.h>
#include <stdlib.h>

void unwind(head, count)
    char **head;
    unsigned short count;
{
    unsigned short i;

    if ( head != NULL) {
        for ( i=0; i<count; i++ ) {
           if (head[i] != NULL) {
               fprintf(stderr,"Freeing %u: 0x%x\n", i, head[i]);
               free(head[i]);
	   }
	}
        fprintf("Freeing head at 0x%x\n", head);
    }
}
