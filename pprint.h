#ifndef _PPRINT_H_
#define _PPRINT_H_

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*(array)))

typedef struct structInfo structInfo;
struct structInfo {
  void *data; /* struct address */
  char *structName; /* struct name */
  int level; /* 0:top level struct, 1: first level struct, ... */
};

extern void printout_struct(char *varName, structInfo info[], int size);

#endif

/* vim: set ts=2 sw=2 expandtab: */
