#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int lcs[MAX_LENGTH + 1][MAX_LENGTH + 1];

int max(int a, int b)
{
    return a > b ? a : b;
}

void find_lcs(char *str1, char *str2, int len1, int len2)
{
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

void print_lcs(char *str1, char *str2, int len1, int len2)
{
    int i = len1, j = len2;
    char result[MAX_LENGTH + 1];
    int idx = 0;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result[idx++] = str1[i - 1];
            i--;
            j--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("LCS of \"%s\" and \"%s\" is \"%s\"\n", str1, str2, strrev(result));
}

int main()
{
    char str1[MAX_LENGTH + 1], str2[MAX_LENGTH + 1];
    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    find_lcs(str1, str2, len1, len2);
    print_lcs(str1, str2, len1, len2);
    return 0;
}
