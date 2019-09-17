#ifndef _PPRINT_H_
#define _PPRINT_H_

#define STRINGIZE(A) #A

extern const char *__progname;

extern void printout_struct(char *instanceName, void* invar, char* structname);

#endif
