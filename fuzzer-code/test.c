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

    // Output[0..1] are magic bytes
    if (output[0] == '\xAB' && output[1] == '\xCD')
    {
        // There is a segfault if output[10] or output[15] == "HELLO" 
        int cmp1 = strncmp(&output[10], "HELLO", 5);
        int cmp2 = strncmp(&output[15], "HELLO", 5);
        int cmp3 = cmp1 + cmp2;
        if(cmp3 == 0)
        {
            int* a = 0;
            int pa = *a;
            return pa;
        }

        // Compare offsets in output
        __int8_t n1 = output[2] + output[4] + output[6] + output[8];
        __int8_t n2 = output[3] + output[5] + output[7] + output[9];

        if(n1 == n2) return 1;
    }

    return 0;
}