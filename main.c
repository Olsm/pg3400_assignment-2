#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc < 2){
        perror("Directory argument missing");
        exit(1);
    }

    char files[32][32];
    int countFiles = getFiles(files, argv[1]);
    if (countFiles == -1)
        return -1;

    size_t lineSize = sizeof(char) * 30;
    char parts[countFiles][30][lineSize];
    if (readFiles(files, countFiles, parts) == -1)
        return -1;


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