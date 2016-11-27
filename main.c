#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    char files[32][32];
    int countFiles = readFiles(files, "mickey");
    if (countFiles == -1) {
        return -1;
    }

    size_t lineSize = sizeof(char) * 30;
    char line[lineSize];
    char parts[countFiles][30][lineSize];
    int count = 0;
    FILE * file = NULL;

    // read each part and add them to arrays of parts
    for (int part = 0; part < countFiles; part++) {
        // Try and open the file for reading, or exit with error
        file = fopen(files[part], "r");
        if (file == NULL){
            perror("Could not open file");
            return -1;
        }

        // Read each line and add them to array of lines in the part
        while (fgets(line, 30, file)) {
            strcpy(parts[part][count], line);
            strtok(parts[part][count], "\n");
            count++;
        }

        count = 0;
        fclose(file);
    }


    FILE *fp;
    fp = fopen("mickey.txt", "w");

    lineSize = sizeof(char) * 90;
    //char tempLine[lineSize];
    //char combined[countFiles][30][lineSize];


    for (int i = 0; i < 30; i++) {
        fprintf(fp, "%s", parts[0][i]);
        fprintf(fp, "%s", parts[2][i]);
        fprintf(fp, "%s\n", parts[4][i]);
    }

    for (int i = 0; i < 30; i++) {
        fprintf(fp, "%s", parts[1][i]);
        fprintf(fp, "%s", parts[3][i]);
        fprintf(fp, "%s\n", parts[5][i]);
    }


    /*
    for (int i = 0; i < 30; ++i) {
        strcpy(tempLine, parts[0][i]);
        strcat(tempLine, parts[2][i]);
        strcat(tempLine, parts[4][i]);
        fprintf(fp, tempLine, "%30c");
    }

    for (int i = 0; i < 30; ++i) {
        strcpy(tempLine, parts[1][i]);
        strcat(tempLine, parts[3][i]);
        strcat(tempLine, parts[5][i]);
        fprintf(fp, tempLine, "%30c");
    }
     */

    fclose(fp);
}