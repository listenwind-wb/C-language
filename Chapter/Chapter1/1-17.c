#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 

#define MAXLINE 1000

int getline(char s[], int lim)
{
    int i = 0;
    int c = 0;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = (char)c;
    if (c == '\n')
    {
        s[i] = (char)c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int main(void)
{
    int len;
    int n = 0;
    char line[MAXLINE];
    char longline[2 * MAXLINE];
    char SavingLine[MAXLINE][2 * MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0 && n < MAXLINE)
    {
        if (len > 80 && len < MAXLINE - 1)
        {
            int i = 0;
            for (i = 0; i <= len; i++)
            {
                SavingLine[n][i] = line[i];
            }
            n++;
        }
        else if (len == MAXLINE - 1 && line[len - 1] != '\n')
        {
            int copied = 0;
            int tocopy = len;
            memcpy(longline, line, tocopy);
            copied += tocopy;
            while (len == MAXLINE - 1 && line[len - 1] != '\n')
            {
                len = getline(line, MAXLINE);
                if (len <= 0) break;
                int remaining = 2 * MAXLINE - 1 - copied;
                if (remaining <= 0)
                {
                    while (getchar() != '\n');
                    break;
                }
                tocopy = (len < remaining) ? len : remaining;
                memcpy(longline + copied, line, tocopy);
                copied += tocopy;
            }
            longline[copied] = '\0';
            copy(SavingLine[n], longline);
            n++;
        }
    }
    printf("大于80个字符的行有：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i + 1);
        for (int j = 0; SavingLine[i][j] != '\0'; j++)
        {
            putchar(SavingLine[i][j]);
        }
    }
    return 0;
}



