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
    char line[MAXLINE];
	char longest[MAXLINE][MAXLINE * 10];
    whlie()
    return 0;
}



