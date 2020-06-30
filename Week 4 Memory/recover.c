#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check if user type in exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    // Open the file that input by user
    FILE *raw_file = fopen(argv[1], "r");
    // Check if the input filename is valid
    if (raw_file == NULL)
    {
        printf("Invalid filename.\n");
        return 1;
    }

    // Generate the first jpg file
    int count = 0;
    char filename[8];
    sprintf(filename, "%03i.jpg", count);
    FILE *img = fopen(filename, "w");

    // Create an array(pointer) to store buffer which contains unsigned char
    unsigned char buffer[512];

    // Read 512 each time until nothing to read
    while (fread(buffer, sizeof(char), 512, raw_file) > 0)
    {
        // Check if the first four bytes are the start of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the original jpg file
            fclose(img);
            // Generate a new jpg file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            fwrite(buffer, sizeof(char), 512, img);
            count++;
        }
        // Keep write into jpg file that is already open
        else
        {
            fwrite(buffer, sizeof(char), 512, img);
        }
    }
    fclose(img);
    fclose(raw_file);
}
