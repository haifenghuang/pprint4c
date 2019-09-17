#include <stdio.h> //sprintf
#include <stdlib.h> //calloc, system
#include <sys/types.h>
#include <unistd.h> //getpid

#include "pprint.h"

extern const char *__progname;

void printout_struct(char *instanceName, void* invar, char* structname) {
    char dbx[1024];
    char gdbcmds[64];
    char structdump[64];

    pid_t pid = getpid();

    sprintf(gdbcmds, "/tmp/gdbcmds.%d", pid);
    sprintf(structdump, "/tmp/struct.dump.%d", pid);

    sprintf(dbx, "echo 'set print pretty on\np (struct %s)*%p\n' > %s", structname, invar, gdbcmds);
    system(dbx);

    sprintf(dbx, "echo 'where\ndetach' | gdb -batch --command=%s %s %d > %s", 
            gdbcmds, __progname, pid, structdump);
    system(dbx);

    /* remove the first line and replace '$1' with instanceName, then cat the file */
    sprintf(dbx, "sed -i -e 's/\\$1/%s/' -e '1d' %s; cat %s", instanceName, structdump, structdump);
    system(dbx);

    unlink(gdbcmds);
    unlink(structdump);

    return;
}

