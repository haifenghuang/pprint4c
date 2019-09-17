#include <stdio.h> //printf
#include <string.h> //memset

#include "pprint.h"

struct person
{
    int age; 
    int height; 
    struct like {
        char *type;
        char *name;
    }like;
};

int main()
{

    struct person johndoe;

    memset(&johndoe, 0x00, sizeof(struct person));

    johndoe.age = 6; 
    johndoe.like.type = "Software-Developing"; 
    johndoe.like.name = "C"; 
    printout_struct(STRINGIZE(johndoe), &johndoe, "person"); 

    johndoe.age = 8; 
    printout_struct(STRINGIZE(johndoe), &johndoe, "person"); 

    printf("Hello World - age: %d\n:", johndoe.age);

    return 0;
}
