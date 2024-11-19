#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // JPEG file header: 0xff 0xd8 0xff 0xe"1" (last byte can be any hexadecimal value)
    // JPEGs are stored back to back

    if (argc != 2)
    {
        printf("Usage : ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("could not open file\n");
        return 1;
    }



    typedef uint8_t BYTE;

    // File *name = malloc space to copy the images

    const int BLOCK_SIZE = 512;

    BYTE block[BLOCK_SIZE];

    int counter = 0;

    char *filename = malloc(8);

    int same = 0;

    FILE *output;

    int read = 0;


    while (fread(block, 512, sizeof(BYTE), input))
    {

        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {


            if (counter > 0)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", counter);

            output = fopen(filename, "w");

            counter++;
            same = 1;
        }

        if (same == 1)
        {

            fwrite(block, 512, sizeof(BYTE), output);

        }
    }

    fclose(input);
    fclose(output);
    free(filename);
}