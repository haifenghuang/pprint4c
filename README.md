# pprint4c
pretty print struct's content at runtime.

## Use
* Need to output struct pointer's contents at runtime
* Don't care about the speed
* For debugging purpose

## Don't use
* For production environment
* Care about the speed

## Example

```c
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

    return 0;
}
```

**Result:**
```
johndoe = {
  age = 6, 
  height = 0, 
  like = {
    type = 0x400934 "Software-Developing", 
    name = 0x400948 "C"
  }
}
```

## Limitation
* Only works for gdb debugger
* Only tested on linux

# see also
[stackoverflow](https://stackoverflow.com/questions/3311182/linux-c-easy-pretty-dump-printout-of-structs-like-in-gdb-from-source-co)

## License
MIT
