#include <stdlib.h>
int countlist(list)
    char **list;
{
    int i;

    for (i = 0; ; i++) {
        if (list[i] == NULL) {
            return i;
        }
    }
}
