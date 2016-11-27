#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int getFiles(char files[32][32], char directory[]) {
    DIR *dir;
    struct dirent *dirEntry;
    int countFiles = 0;

    dir = opendir(directory);
    if (!dir) {
        perror ("could not read directory");
        return -1;
    }

    while ((dirEntry = readdir(dir)) != NULL) {
        if (dirEntry->d_type == DT_REG) {
            strcpy(files[countFiles], "mickey/");
            strcat(files[countFiles], dirEntry->d_name);
            countFiles++;
        }
    }
    closedir(dir);

    qsort (files[0], countFiles, sizeof(files[0]), compare_func);

    return countFiles;
}

int readFiles(char files[32][32], int fileCount, char parts[fileCount][30][sizeof(char)*30]) {
    int count = 0;
    FILE * file = NULL;
    char line[sizeof(char)*30];

    // read each part and add them to arrays of parts
    for (int part = 0; part < fileCount; part++) {
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

    return 0;
}


int compare_func(const void *a,const void *b) {
    return (strcmp((char *)a,(char *)b));
}