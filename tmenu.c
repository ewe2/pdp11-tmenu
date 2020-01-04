#include <stdio.h>
#include <strings.h>
#include <sys/types.h>

extern getdir();
extern displaymenu();
extern countlist();
extern compare();

void usage(cmd)
    char *cmd;
{
    fprintf(stderr, "%s directory [cmd]\n",cmd);
}

int main(argc,argv)
     int argc;
     char *argv[];
{
    char *cmd ="";
    char *dir ="";
    char **namelist;
    int count;
    int input;
    int scanr;

    if ((argc < 2) || (argc > 3)) {
        usage((char *)argv[0]);
        return(1);
    }
    dir = (char *) argv[1];
    if (argc == 3) {
        cmd = (char *) argv[2];
    }
    namelist = getdir(dir);
    count = countlist(namelist);
    if ( namelist == NULL ) {
        fprintf(stderr, "Could not open %s!\n", argv[1]);
        return(1);
    }
    qsort(namelist, count, sizeof(char *), compare);
    displaymenu(namelist);

    input=0;
    while (1) {
        printf("\n> ");
        fflush(stdout);
        scanr = scanf("%4d",&input);
        if ( scanr != 1) {
            fprintf(stderr, "Could not parse input.\n");
            return(3);
        }
        if ((input > 0 ) && (input <= count)) {
            break;
	}
        printf("Input not in range.\n");
    }

    count=execute(dir, cmd, namelist[(input - 1)]);

    return(count); /* Only reached if error */
}
