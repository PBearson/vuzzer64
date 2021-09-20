#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* fptr = fopen(argv[1], "r");

    char output[1024];

    if(fptr == NULL)
    {
        printf("That file does not exist\n");
        return 0;
    }

    fscanf(fptr, "%s", output);

    // Output[2..4] cannot be "BAD"
    int cmp = strncmp(&output[2], "BAD", 3);
    if(cmp == 0) abort();

    // Output[0..1] are magic bytes
    if(output[0] != '\xAB' || output[1] != '\xCD') return 0;

    // There is a segfault if output[15] == "HELLO"
    cmp = strncmp(&output[15], "HELLO", 5);
    if(cmp == 0)
    {
        int* a = 0;
        int pa = *a;
        return pa;
    }

    return 0;
}