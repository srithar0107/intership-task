
#include <stdio.h>
#include <string.h>

void compress(char* input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", input[i], count);
    }
    printf("\n");
}

void decompress(char* input) {
    for (int i = 0; input[i] != '\0'; i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0';
        for (int j = 0; j < count; j++) {
            printf("%c", ch);
        }
    }
    printf("\n");
}

int main() {
    char data[] = "aaaabbbccdaa";
    printf("Original: %s\n", data);
    printf("Compressed: ");
    compress(data);

    char compressed[] = "a4b3c2d1a2";
    printf("Decompressed: ");
    decompress(compressed);

    return 0;
}
