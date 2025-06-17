
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    // 1. Create and Write to a File
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(fp, "This is a test file.\n");
    fclose(fp);

    // 2. Append Data
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for append!\n");
        return 1;
    }
    fprintf(fp, "This line is appended.\n");
    fclose(fp);

    // 3. Read File
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("Reading file content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
