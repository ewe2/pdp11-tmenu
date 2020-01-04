#include <stdio.h>
#include <strings.h>
#include <sys/ioctl.h>

extern countlist();

void displaymenu(namelist)
    char **namelist;
{
    unsigned short max;
    unsigned short l;
    unsigned short pass;
    unsigned short i;
    unsigned short fsize;
    unsigned short dsize;
    unsigned short nsize;
    int rc;
    char fstr[15];
    char itoa[17];
    struct winsize w;
    unsigned short cols;
    unsigned short dcols;
    int entries;

    max = 0;
    entries = countlist(namelist);
    for ( i=0 ; i < entries ; i++ ) {
        l = strlen(namelist[i]);
        if ( l > max ) {
            max = l;
	}
    }
    /* End of pass 1 */
    sprintf(itoa,"%u",entries);
    fsize = strlen(itoa);
    /* % <num> u colon space % - <num> s space" */
    sprintf(fstr, "%%%uu: %%-%us ", fsize, max);
    rc = ioctl(stdout,TIOCGWINSZ,&w);
    if (rc != 0) {
        /* fprintf(stderr,"Couldn't get width; assuming 80 columns.\n"); */
        cols = 80;
    } else {
        cols = w.ws_col;
    }
    dcols = (cols - 1) / (max + fsize + 2);
    for ( i=0 ; i < entries ; i++ ) {
	printf(fstr, (i + 1), namelist[i]);
        if ((( (i + 1) % dcols ) == 0) || ((i + 1) == entries)) {
            printf("\n");
        }
    }
}
