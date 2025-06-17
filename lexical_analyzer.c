
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char* word) {
    const char* keywords[] = {"int", "float", "if", "else", "while", "return", "for"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE* fp = fopen("input.c", "r");
    char ch, buffer[50];
    int i = 0;

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0';
            i = 0;
            if (strlen(buffer) > 0) {
                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=') {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
