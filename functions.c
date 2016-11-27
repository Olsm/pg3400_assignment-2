#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int readFiles(char files[32][32], char directory[]) {
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

int compare_func(const void *a,const void *b) {
    return (strcmp((char *)a,(char *)b));
}