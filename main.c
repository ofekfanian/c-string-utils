// main.c
#include <stdio.h>
#include "functions.h"

// remove trailing '\n' that fgets stores
void stripNewline(char *s)
{
    char *p = s;
    while (*p != '\0' && *p != '\n')
        p++;
    if (*p == '\n')
        *p = '\0';
}

int main(void)
{
    char choice = 0;

    while (choice != 'e' && choice != 'E')
    {
        int c;
        printf("\n--- Main Menu ---\n");
        printf("Option 1 - Matrix border sum\n");
        printf("Option 2 - Concatenate two strings\n");
        printf("Option 3 - Search for a substring\n");
        printf("Option e - Exit\n");
        printf("Enter choice: ");

        // read single menu choice
        int ch = getchar();
        choice = (char)ch;

        // Clear the rest of the line (flush buffer)
        if (ch != '\n' && ch != EOF) {
             while ((c = getchar()) != '\n' && c != EOF) { }
        }

        switch (choice)
        {
            case '1':
            {
                int matrix[ROWS][COLS];

                getMatrix(&matrix[0][0]);
                printMatrix(&matrix[0][0]);

                printf("\nBorder items (clockwise): ");
                int sum = mysum(&matrix[0][0]);
                printf("The sum of the border items is: %d\n", sum);

                break;
            }

            case '2':
            {
                char strDestination[MAX_LEN];
                char strSource[MAX_LEN];

                printf("Please enter destination string:\n");
                fgets(strDestination, MAX_LEN, stdin);
                stripNewline(strDestination);

                printf("Please enter source string:\n");
                fgets(strSource, MAX_LEN, stdin);
                stripNewline(strSource);

                mystrcat(strDestination, strSource);
                printf("Result: %s\n", strDestination);

                break;
            }

            case '3':
            {
                char str[MAX_LEN];
                char strSearch[MAX_LEN];

                printf("Please enter the main string (str):\n");
                fgets(str, MAX_LEN, stdin);
                stripNewline(str);

                printf("Please enter the substring to search for (strSearch):\n");
                fgets(strSearch, MAX_LEN, stdin);
                stripNewline(strSearch);

                char *res = myStrstr(str, strSearch);

                if (res == NULL) {
                    printf("strSearch was not found in str.\n");
                } else {
                    int index = (int)(res - str);

                    printf("strSearch is found in str!\n");
                    printf("index: %d\n", index);
                    printf("char: '%c'\n", *res);
                }

                break;
            }

            case 'e':
            case 'E':
                printf("Exiting...\n");
                break;

            // Handle newline explicitly to avoid printing "Wrong option" on empty Enter
            case '\n':
                break;

            default:
                printf("Wrong option, please try again.\n");
                break;
        }
    }

    return 0;
}