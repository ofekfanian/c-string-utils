//
// Created by ofek fanian on 07/12/2025.
//
#ifndef SYSTEMPROGRAMING_FUNCTIONS_H
#define SYSTEMPROGRAMING_FUNCTIONS_H

#define MAX_LEN 200
#define COLS 4
#define ROWS 3

void getMatrix(int *matPtr);
void printMatrix(const int *matPtr);
int  mysum(const int *matPtr);
char *mystrcat(char *strDestination, const char *strSource);
int  strSpecialCmp(const char *str, const char *strSearch);
char *myStrstr(const char *str, const char *strSearch);

#endif //SYSTEMPROGRAMING_FUNCTIONS_H