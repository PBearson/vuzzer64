#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fptr = fopen(argv[1], "r");

    char output[32];

    if(fptr == NULL)
    {
        printf("That file does not exist\n");
        return 0;
    }

    fscanf(fptr, "%s", output);

    printf("File contents: %s\n", output);

    int i_value = atoi(output);

    printf("Int value: %d\n", i_value);

    if(i_value > 1000)
    {
        int a = 5;
        int b = 0;
        return a / b;
    }

    if(output[28] == 'A')
    {
        if(output[29] == 'B')
        {
            if(output[30] == 'C')
            {
                if(output[31] == 'D')
                {
                    printf("ABORT\n");
                    abort();
                }
            }
        }
    }

    return 0;
}