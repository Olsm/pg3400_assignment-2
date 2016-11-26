#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    DIR *dir;
    struct dirent *dirEntry;
    char files[32][32];
    int countFiles = 0;

    dir = opendir("mickey");
    if (!dir) {
        perror ("could not read directory");
        return -1;
    }

    while ((dirEntry = readdir(dir)) != NULL) {
        if (dirEntry->d_type == DT_REG) {
            strcpy(files[countFiles], dirEntry->d_name);
            countFiles++;
        }
    }
    closedir(dir);

    for (int i = 0; i < countFiles; ++i) {
        printf("%s \n", files[i]);
    }
}