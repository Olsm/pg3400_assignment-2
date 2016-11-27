#ifndef PG3400_ASSIGNMENT_2_FUNCTIONS_H
#define PG3400_ASSIGNMENT_2_FUNCTIONS_H

int getFiles(char files[32][32], char directory[]);
int readFiles(char files[32][32], int fileCount, char parts[fileCount][30][sizeof(char)*30]);
int compare_func(const void *a,const void *b);

#endif //PG3400_ASSIGNMENT_2_FUNCTIONS_H
