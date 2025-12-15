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
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = (char)c;
    if (c == '\n') {
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
    int maxlen = 0;
    int total;
    char line[MAXLINE];
    char longest[MAXLINE];

    longest[0] = '\0';

    while ((len = getline(line, MAXLINE)) > 0) {
        if (!(len == MAXLINE - 1 && line[len - 1] != '\n')) {
            total = len;
            if (total > maxlen) {
                maxlen = total;
                copy(longest, line);
            }
        }
        else {
            total = len;
            int copied = 0;

            if (len > 0) {
                int remaining = (MAXLINE - 1) - copied;
                int tocopy = (len < remaining) ? len : remaining;
                if (tocopy > 0) {
                    memcpy(longest + copied, line, tocopy);
                    copied += tocopy;
                }
            }

            while (len == MAXLINE - 1 && line[len - 1] != '\n') {
                len = getline(line, MAXLINE);
                if (len <= 0) break;

                total += len;

                int remaining = (MAXLINE - 1) - copied;
                if (remaining > 0 && len > 0) {
                    int add = (len < remaining) ? len : remaining;
                    memcpy(longest + copied, line, add);
                    copied += add;
                }
            }

            if (total > maxlen) {
                maxlen = total;
                if (copied >= MAXLINE) copied = MAXLINE - 1;
                longest[copied] = '\0';
            }
        }
    }

    if (maxlen > 0) {
        printf("最长行长度：%d\n", maxlen);
        printf("最长行的尽可能多的左端内容（至多%d字符）：\n%s", MAXLINE - 1, longest);
    }
    else {
        printf("没有输入或最长行长度为0。\n");
    }

    return 0;
}



