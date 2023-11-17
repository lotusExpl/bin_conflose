#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeBinaryToFile(FILE *newFile, char character) {
    for (int i = 7; i >= 0; i--) {
        fprintf(newFile, "%d", (character >> i) & 1);
    }
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <initial_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the initial file for reading
    FILE *initialFile = fopen(argv[1], "r");
    if (initialFile == NULL) {
        perror("Error opening initial file");
        return EXIT_FAILURE;
    }

    // Create a new file for writing
    char* filename = "conflose.c";
    //strcat(filename, (char*)argv[1]);
    FILE *newFile = fopen(filename, "w");
    if (newFile == NULL) {
        perror("Error creating new file");
        fclose(initialFile);
        return EXIT_FAILURE;
    }

    // Process each character in the initial file
    int ch;
    while ((ch = fgetc(initialFile)) != EOF) {
        // Write the binary representation of the character to the new file
        writeBinaryToFile(newFile, (char)ch);
    }

    // Close the files
    fclose(initialFile);
    fclose(newFile);
    return EXIT_SUCCESS;
}

