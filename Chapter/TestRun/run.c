#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 



/* 完整程序：练习 1-16（只修改 main） */
/* 保存行的左端尽可能多的文本并统计任意长度行的真实长度 */



#define MAXLINE 10   /* 缓冲区大小（可调整） */

/* getLine: 读入一行到 s，至多读 lim-1 个字符；返回读入的长度（包含 '\n' 若存在） */
int getLine(char s[], int lim)
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

/* copy: 把 from 拷贝到 to（书中给出的简单实现） */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* 仅替换 main（其余函数与书中类似） */
int main(void)
{
    int len;                    /* 本次 getLine 返回的块长度 */
    int maxlen = 0;             /* 已知最长行的真实长度 */
    int total;                  /* 当前整行真实长度（累加） */
    char line[MAXLINE];         /* getLine 的缓冲区 */
    char longest[MAXLINE];      /* 保存最长行的尽可能多的左侧部分 */

    longest[0] = '\0';

    while ((len = getLine(line, MAXLINE)) > 0) {
        /* 如果这次块不是满缓冲（len < MAXLINE-1）或包含换行，说明此行在单块内结束 */
        if (!(len == MAXLINE - 1 && line[len - 1] != '\n')) {
            /* 单块完整读到一行（包含 '\n' 或读到 EOF/短于缓冲） */
            total = len;
            if (total > maxlen) {
                maxlen = total;
                /* 直接拷贝整行（line 已以 '\0' 结尾） */
                copy(longest, line);
            }
        }
        else {
            /* 这一块是“满缓冲且不以换行结束”——说明该行很长，需要继续读后续块 */
            total = len;
            int copied = 0; /* 已向 longest 写入的字符数（不含 '\0'） */

            /* 把当前块尽可能拷入 longest（注意不要超过 MAXLINE-1） */
            if (len > 0) {
                int remaining = (MAXLINE - 1) - copied;
                int tocopy = (len < remaining) ? len : remaining;
                if (tocopy > 0) {
                    memcpy(longest + copied, line, tocopy);
                    copied += tocopy;
                }
            }

            /* 继续读后续块，直到读到包含 '\n' 的块或读到长度不足缓冲的块 */
            while (len == MAXLINE - 1 && line[len - 1] != '\n') {
                len = getLine(line, MAXLINE);
                if (len <= 0) break; /* EOF 保护 */

                total += len;

                /* 如果 longest 还有剩余空间，继续把后续块的一部分拷入 */
                int remaining = (MAXLINE - 1) - copied;
                if (remaining > 0 && len > 0) {
                    int add = (len < remaining) ? len : remaining;
                    memcpy(longest + copied, line, add);
                    copied += add;
                }
            }

            /* 该行现在已读完（或遇到 EOF），比较并在需要时更新最长记录 */
            if (total > maxlen) {
                maxlen = total;
                if (copied > 0) {
                    if (copied >= MAXLINE) copied = MAXLINE - 1;
                    longest[copied] = '\0';
                }
                else {
                    /* 如果没有拷到任何字符（极少见），仍保证 longest 是空串 */
                    longest[0] = '\0';
                }
            }
        }
    }

    if (maxlen > 0) {
        printf("最长行长度: %d\n", maxlen);
        printf("最长行的尽可能多的部分如下:\n%s", longest);
    }

    return 0;
}



