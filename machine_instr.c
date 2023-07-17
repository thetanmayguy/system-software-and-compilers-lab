#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char *fields[4];
        int count = 0;

        char *token = strtok(line, " \n");
        while (token != NULL && count < 4) {
            fields[count] = token;
            count++;
            token = strtok(NULL, " \n");
        }

        if (count == 2) {
            fprintf(outputFile, "LD R0, %s\n", fields[1]);
            fprintf(outputFile, "ST %s, R0\n", fields[0]);
        } else if (count == 4) {
            fprintf(outputFile, "LD R0, %s\n", fields[1]);

            if (strcmp(fields[2], "+") == 0) {
                fprintf(outputFile, "ADD R0, %s\n", fields[3]);
            } else if (strcmp(fields[2], "-") == 0) {
                fprintf(outputFile, "SUB R0, %s\n", fields[3]);
            } else if (strcmp(fields[2], "*") == 0) {
                fprintf(outputFile, "MUL R0, %s\n", fields[3]);
            } else if (strcmp(fields[2], "/") == 0) {
                fprintf(outputFile, "DIV R0, %s\n", fields[3]);
            } else {
                fprintf(outputFile, "Unsupported Operator\n");
            }

            fprintf(outputFile, "ST %s, R0\n", fields[0]);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}