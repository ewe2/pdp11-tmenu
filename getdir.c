#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/dir.h>

extern void unwind();

char **getdir(dirname)
    char *dirname;
{
    DIR *dirp;
    u_short index;
    u_short namlen;
    u_short count;
    u_short pass;
    char *dname;
    char *ename;
    char **namelist;
    struct direct *dp;

    dirp = opendir(dirname);
    if (dirp == NULL) {
        return NULL;
    }
    for ( pass = 1; pass < 3; pass++ ) {
        count = 0;
        for ( dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
            dname = dp->d_name;
            /* This directory and parent are special and not counted. */
            if (!strcmp(dname,".") || !strcmp(dname,"..")) {
                continue;
            }
            /* Neither is the magic name "lib" */
            if (!strcmp(dname,"lib")) {
                continue;
	    }
            namlen = strlen(dname);
            if ( pass == 2) {
                /* Second pass: append the name to our list */
                ename = (char *) calloc(namlen+1, 1); /* sizeof(char) == 1 */

                if (ename == NULL) {
                    fprintf(stderr, "Could not allocate memory for name!\n");
                    unwind(namelist,count);
                    return NULL;
	        }
                strncpy(ename,dname,namlen);
                ename[namlen] = '\0';
                namelist[count] = ename;
	    }
            count++;
	}
        rewinddir(dirp);
        if ( pass == 1 ) {
           /* End of pass 1: allocate memory for list */
           namelist = (char **) calloc (count + 1, sizeof(char *));
           if (namelist == NULL) {
               fprintf(stderr, "Could not allocate memory for namelist!\n");
               return NULL;
	   }
           namelist[count] = NULL;
	}
    }
    closedir(dirp);
    return namelist;
}

    
