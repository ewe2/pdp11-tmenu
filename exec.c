#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>


extern char **environ;
extern int errno;

int execute(dir, cmd, item)
    char *dir;
    char *cmd;
    char *item;
{
    /* If cmd is empty, we execute dir/item ; if it is not, we execute
       cmd dir/item */
    char *fullarg;
    char *basecmd;
    unsigned short argspace;

    int c;
    argspace = strlen(dir) + strlen(item) + 2;
    fullarg = (char *) calloc (argspace, 1);
    if (fullarg == NULL) {
        fprintf(stderr, "Couldn't allocate %u bytes for argument!\n",argspace);
        return(2);
    }
    sprintf(fullarg, "%s/%s", dir, item);

    c = strcmp(cmd,"");
    if (! c) {
        cmd = fullarg;
    }
    basecmd = rindex(cmd, '/') + 1;
    if (basecmd == 1) {
       basecmd = cmd;
    }

    fflush(stdout);
    if (fullarg == NULL) {
        execl(cmd, basecmd, NULL);
    } else {
        execl(cmd, basecmd, fullarg, NULL);
    }
    /* No return if it worked. */
    perror();
    return errno;
}
