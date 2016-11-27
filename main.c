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
            strcpy(files[countFiles], "mickey/");
            strcat(files[countFiles], dirEntry->d_name);
            countFiles++;
        }
    }
    closedir(dir);

    char line[sizeof(char)*30];
    char lines[2048][sizeof(line)];
    int count = 0;
    FILE * file = NULL;

    for (int i = 0; i < countFiles; ++i) {
        // Try and open the file for reading, or exit with error
        file = fopen(files[i], "r");
        if (file == NULL){
            perror("Could not open file");
            return -1;
        }

        // Read each line and add them to array of lines
        while (fgets(line, sizeof(char)*30, file)) {
            strcpy(lines[count], line);
            count++;
        }

        fclose(file);
    }


    FILE *fp;
    fp = fopen("mickey/mickey.txt", "w");

    int i;
    for (i = 0; i < count; i++) {
        fprintf(fp, lines[i]);
    }

    fclose(fp);
}