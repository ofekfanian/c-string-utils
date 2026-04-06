// functions.c
#include <stdio.h>
#include "functions.h"

// ---------------------- OPTION 1 --------------------------

void getMatrix(int *matP)
{
    for (int r = 0; r < ROWS; r++)
    {
        printf("Please enter %d numbers for row %d -> ", COLS, r);
        for (int c = 0; c < COLS; c++)
        {
            scanf("%d", matP);
            matP++; // move to next matrix cell
        }
    }
    // Clean the buffer (consume the newline char left by scanf)
    // This prevents the menu in main from behaving incorrectly
    getchar();
}

void printMatrix(const int *matPtr)
{
    printf("Matrix from user:\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%5d ", *matPtr);
            matPtr++;      // move to next element
        }
        printf("\n");
    }
}

int mysum(const int *matPtr)
{
    int sum = 0;

    // Top row
    for (int j = 0; j < COLS; j++)
    {
        printf("%d ", *(matPtr + j));   // *(matP + j) ---> matrix[0][j]
        sum += *(matPtr + j);
    }

    // Right column
    for (int i = 1; i < ROWS - 1; i++)
    {
        const int *p = matPtr + i * COLS + (COLS - 1);  // &matrix[i][COLS-1]
        printf("%d ", *p);
        sum += *p;
    }

    // Bottom row (right to left)
    if (ROWS > 1)
    {
        for (int j = COLS - 1; j >= 0; j--)
        {
            const int *p = matPtr + (ROWS - 1) * COLS + j; // &matrix[ROWS-1][j]
            printf("%d ", *p);
            sum += *p;
        }
    }

    // Left column
    for (int i = ROWS - 2; i >= 1; i--)
    {
        const int *p = matPtr + i * COLS; // &matrix[i][0]
        printf("%d ", *p);
        sum += *p;
    }
    printf("\n");
    return sum;
}

// ---------------------- OPTION 2 --------------------------

char *mystrcat(char *strDestination, const char *strSource)
{
    char *destPtr = strDestination;   // must be non-const because we modify destination

    // Move to the end of destination string
    while (*destPtr != '\0')
    {
        destPtr++;
    }

    // Copy source to destination
    const char *srcPtr = strSource;
    while (*srcPtr != '\0')
    {
        *destPtr = *srcPtr;
        destPtr++;
        srcPtr++;
    }
    *destPtr = '\0';     // add null terminator
    return strDestination;
}

// ---------------------- OPTION 3 --------------------------

int strSpecialCmp(const char *str, const char *strSearch)
{
    if (*strSearch == '\0')
        return 1;

    if (*str == '\0' || *str != *strSearch)
        return 0;

    return strSpecialCmp(str + 1, strSearch + 1);
}

char *myStrstr(const char *str, const char *strSearch)
{
    // Return NULL if either string is empty
    if (*str == '\0' || *strSearch == '\0')
        return NULL;

    // If matches here, return current position
    if (strSpecialCmp(str, strSearch))
        return (char *)str;

    // Recursive step: try next character
    return myStrstr(str + 1, strSearch);
}